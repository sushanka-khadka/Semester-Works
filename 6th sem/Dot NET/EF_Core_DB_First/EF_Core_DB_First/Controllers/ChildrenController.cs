using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using EF_Core_DB_First.Data;
using EF_Core_DB_First.Models;
using EF_Core_DB_First.ViewModels;

namespace EF_Core_DB_First.Controllers
{
    public class ChildrenController : Controller
    {
        private readonly EF_Core_DbContext _context;

        public ChildrenController(EF_Core_DbContext context)
        {
            _context = context;
        }

        // GET: Children
        public async Task<IActionResult> Index()
        {
            var child = _context.Children.Include(c => c.Parents).ToListAsync();    // recommended to use ViewModel to avoid sensitive data exposure
            return View(await child);
        }

        // GET: Children/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var child = await _context.Children.Include(c => c.Parents)
                .FirstOrDefaultAsync(m => m.ChildId == id);     // returning navigation property can be risky
            var childVM = await _context.Children.Select(c => new ChildViewModel
            {
                ChildId = c.ChildId,
                Name = c.Name,
                Gender = c.Gender,
                AvailableParents = c.Parents.Select(p => new SelectListItem
                {
                    Value = p.ParentId.ToString(),
                    Text = p.Name,
                    Selected = true
                }).ToList()
            }).SingleOrDefaultAsync(c => c.ChildId == id);

            if (child == null)
            {
                return NotFound();
            }

            return View(childVM);
        }

        // GET: Children/Create
        public async Task<IActionResult> Create()
        {
            var childVM = new ChildViewModel
            {
                AvailableParents = await _context.Parents.Select(p => new SelectListItem
                {
                    Value = p.ParentId.ToString(),
                    Text = p.Name,
                    Selected = false
                }).ToListAsync()
            };

            //ViewData["ParentsList"] = new SelectList(_context.Parents, "ParentId", "Name");
            return View(childVM);
        }

        // POST: Children/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("ChildId,Name,Gender,SelectedParentIds")] ChildViewModel childVM)
        {
            if (ModelState.IsValid)
            {
                var child = new Child
                {
                    ChildId = childVM.ChildId,
                    Name = childVM.Name,
                    Gender = childVM.Gender,
                    Parents = _context.Parents.Where(p => childVM.SelectedParentIds.Contains(p.ParentId)).ToList()                    
                };            
                _context.Add(child);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            return View();
        }

        // GET: Children/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }
            
            //var child = await _context.Children.Include(c => c.Parents).SingleOrDefaultAsync(c => c.ChildId == id);
            var childVM = _context.Children.Select(c => new ChildViewModel
            {
                ChildId = c.ChildId,
                Name = c.Name,
                Gender = c.Gender,
                SelectedParentIds = c.Parents.Select(p => p.ParentId).ToList(),
            }).SingleOrDefault(c => c.ChildId == id);
            
            // Load available parents for selection
            childVM.AvailableParents = await _context.Parents.Select(p => new SelectListItem
            {
                Value = p.ParentId.ToString(),
                Text = p.Name,
                Selected = childVM.SelectedParentIds.Contains(p.ParentId)
            }).ToListAsync();

            if (childVM == null)
            {
                return NotFound();
            }
            //ViewData["ParentChildId"] = new SelectList(_context.Parents, "ChildId", "Name", child.Parents);   // selectlist won't work for multiple selected values
            //ViewData["ParentsList"] = new MultiSelectList(_context.Parents.ToList(), "ParentId", "Name", childVM.Parents.Select(p => p.ParentId).ToList());            
            //ViewData["ParentsList"] = new MultiSelectList(_context.Parents.ToList(), "ParentId", "Name", childVM.SelectedParentIds);            

            return View(childVM);
        }

        // POST: Children/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("ChildId,Name,Gender,SelectedParentIds")] ChildViewModel childVM)
        {
            if (id != childVM.ChildId)
            {
                return NotFound();
            }
            foreach(var item in Request.Form)
            {
                Console.WriteLine(item);
            }

            if (ModelState.IsValid)
            {
                Console.WriteLine("\n\nModel Valid\n");
                try
                {
                    var child = await _context.Children.Include(c => c.Parents)
                        .SingleOrDefaultAsync(c => c.ChildId == id);    //Load existing Child entity from DB and update navigation property instead of creating a new object.

                    if (child == null) return NotFound();
                    // Update scalar properties
                    child.Name = childVM.Name;
                    child.Gender = childVM.Gender;
                    // Update many-to-many relationship
                    child.Parents.Clear(); // remove old associations
                    var Parents = _context.Parents.Where(p => childVM
                        .SelectedParentIds.Contains(p.ParentId)).ToList();
                    foreach (var parent in Parents)
                    {
                        child.Parents.Add(parent); // add new associations
                    }
                    await _context.SaveChangesAsync();

                    /* This will detach the existing Child entity and EF thinks it’s new → may overwrite existing relationships incorrectly.
                    var child = new Child
                    {
                        ChildId = childVM.ChildId,
                        Name = childVM.Name,
                        Gender = childVM.Gender,
                        Parents = _context.Parents.Where(p => childVM.SelectedParentIds.Contains(p.ParentId)).ToList()
                    };
                    _context.Update(child);
                    await _context.SaveChangesAsync();
                    */
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!ChildExists(childVM.ChildId))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }                
                return RedirectToAction(nameof(Index));
            }
            Console.WriteLine("\n\nModel invalid\n");
            return View();
        }

        // GET: Children/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }
            var childVM = new ChildViewModel
            {
                AvailableParents = await _context.Parents.Select(p => new SelectListItem
                {
                    Value = p.ParentId.ToString(),
                    Text = p.Name,
                    Selected = false
                }).ToListAsync()
            };

            //var child = await _context.Children.Include(c => c.Parents)
                //.FirstOrDefaultAsync(m => m.ChildId == id);
            if (childVM == null)
            {
                return NotFound();
            }

            return View(childVM);
        }

        // POST: Children/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var child = await _context.Children.FindAsync(id);
            if (child != null)
            {
                _context.Children.Remove(child);
            }

            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool ChildExists(int id)
        {
            return _context.Children.Any(e => e.ChildId == id);
        }
    }
}

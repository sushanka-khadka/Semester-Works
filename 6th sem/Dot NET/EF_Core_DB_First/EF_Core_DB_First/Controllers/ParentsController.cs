using EF_Core_DB_First.Data;
using EF_Core_DB_First.Models;
using EF_Core_DB_First.ViewModels;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;

namespace EF_Core_DB_First.Controllers
{
    public class ParentsController : Controller
    {
        private readonly EF_Core_DbContext _context;

        public ParentsController(EF_Core_DbContext context)
        {
            _context = context;
        }

        // GET: Parents
        public async Task<IActionResult> Index()
        {
            var eF_Core_DbContext = _context.Parents.Include(p => p.Employee).ToListAsync();  // will return Entity Model (vulerable to sensitive data)
            //var eF_Core_DbContext = _context.Parents.Select(p => new ParentViewModel
            //{
            //    ParentId = p.ParentId,
            //    Name = p.Name,
            //    HasChildren = p.HasChildren,
            //    EmpId = p.EmpId,
            //}).ToListAsync();
            return View(await eF_Core_DbContext);
        }

        // GET: Parents/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var parent = await _context.Parents.Include(p => p.Employee).FirstOrDefaultAsync(m => m.ParentId == id);
            if (parent == null)
            {
                return NotFound();
            }

            return View(parent);
        }

        // GET: Parents/Create
        public IActionResult Create()
        {
            //ViewData["EmpId"] = new SelectList(_context.Employees, "EmpId", "Address");
            ViewData["EmpId"] = new SelectList(_context.Employees, "EmpId", "FullName");
            return View();
        }

        // POST: Parents/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("ParentId,Name,HasChildren,EmpId")] ParentViewModel parentVM)
        {
            if (ModelState.IsValid)
            {
                var parent = new Parent
                {
                    ParentId = parentVM.ParentId,
                    Name = parentVM.Name,
                    HasChildren = parentVM.HasChildren,
                    EmpId = parentVM.EmpId,
                };
                _context.Add(parent);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            return View();
        }

        // GET: Parents/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var parent = await _context.Parents.Select(p => new ParentViewModel
            {
                ParentId = p.ParentId,
                Name = p.Name,
                HasChildren = p.HasChildren,
                EmpId = p.EmpId,
            }).SingleOrDefaultAsync(p => p.ParentId == id);
                
            if (parent == null)
            {
                return NotFound();
            }
            //ViewData["EmpId"] = new SelectList(_context.Employees, "EmpId", "Address", parent.EmpId);
            ViewData["EmpId"] = new SelectList(_context.Employees, "EmpId", "FullName", parent.EmpId);
            return View(parent);
        }

        // POST: Parents/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("ParentId,Name,HasChildren,EmpId")] ParentViewModel parentVM)
        {
            if (id != parentVM.ParentId)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                var parent = new Parent
                {
                    ParentId = parentVM.ParentId,
                    Name = parentVM.Name,
                    HasChildren = parentVM.HasChildren,
                    EmpId = parentVM.EmpId,
                };
                try
                {
                    _context.Update(parent);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!ParentExists(parent.ParentId))
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
            //ViewData["EmpId"] = new SelectList(_context.Employees, "EmpId", "Address", parent.EmpId);
            //ViewData["EmpId"] = new SelectList(_context.Employees, "EmpId", "EmpId", parent.EmpId);
            return View();
        }

        // GET: Parents/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var parent = await _context.Parents
                .Include(p => p.Employee)
                .FirstOrDefaultAsync(m => m.ParentId == id);

            var parentVM = await _context.Parents.Select(p => new ParentViewModel
            {
                ParentId = p.ParentId,
                Name = p.Name,
                HasChildren = p.HasChildren,
                EmpId = p.EmpId,
            }).SingleOrDefaultAsync(p => p.ParentId == id);


            if (parent == null)
            {
                return NotFound();
            }
            ViewData["Employee"] = parent.Name;
            return View(parentVM);
        }

        // POST: Parents/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var parent = await _context.Parents.FindAsync(id);
            if (parent != null)
            {
                _context.Parents.Remove(parent);
            }

            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool ParentExists(int id)
        {
            return _context.Parents.Any(e => e.ParentId == id);
        }
    }
}

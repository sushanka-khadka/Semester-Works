using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using EF_Core_DB_First.Data;
using EF_Core_DB_First.Models;

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
            var child = _context.Children.Include(c => c.Parents).ToListAsync();
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
                .FirstOrDefaultAsync(m => m.ChildId == id);
            if (child == null)
            {
                return NotFound();
            }

            return View(child);
        }

        // GET: Children/Create
        public IActionResult Create()
        {
            ViewData["ParentChildId"] = new SelectList(_context.Parents, "ChildId", "Name");
            return View();
        }

        // POST: Children/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("ChildId,Name,Gender")] Child child)
        {
            if (ModelState.IsValid)
            {
                _context.Add(child);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            return View(child);
        }

        // GET: Children/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }
            var child = await _context.Children.Include(c => c.Parents).SingleOrDefaultAsync(c => c.ChildId == id);
            if (child == null)
            {
                return NotFound();
            }
            //ViewData["ParentChildId"] = new SelectList(_context.Parents, "ChildId", "Name", child.Parents);   // selectlist won't work for multiple selected values
            ViewData["ParentsList"] = new MultiSelectList(_context.Parents.ToList(), "ChildId", "Name", child.Parents.Select(p => p.ParentId).ToList());
            return View(child);
        }

        // POST: Children/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("ChildId,Name,Gender")] Child child)
        {
            if (id != child.ChildId)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(child);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!ChildExists(child.ChildId))
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
            return View(child);
        }

        // GET: Children/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var child = await _context.Children.Include(c => c.Parents)
                .FirstOrDefaultAsync(m => m.ChildId == id);
            if (child == null)
            {
                return NotFound();
            }

            return View(child);
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

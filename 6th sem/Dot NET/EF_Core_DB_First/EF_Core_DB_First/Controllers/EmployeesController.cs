using EF_Core_DB_First.Data;
using EF_Core_DB_First.Models;
using EF_Core_DB_First.ViewModels;
using Microsoft.AspNetCore.Mvc;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Microsoft.EntityFrameworkCore;

namespace EF_Core_DB_First.Controllers
{
    public class EmployeesController : Controller   //Extension method must be defined in a non-generic static class
    {
        private readonly EF_Core_DbContext _context;

        public EmployeesController(EF_Core_DbContext context)
        {
            _context = context;
        }

        // GET: Employees
        public async Task<IActionResult> Index()
        {
            /* ToList() will Sends the query to the database & Waits(blocks) until results come back.
            Whereas in ToListAsync() =>  current thread can do other work while waiting for results. */
            //var eF_Core_DbContext = await _context.Employees.ToListAsync();  // will return Model 

            var eF_Core_DbContext = _context.Employees.Select(e => new EmployeeViewModel
            {
                EmpId = e.EmpId,
                FullName = e.FullName,
                Address = e.Address,
                Phone = e.Phone,
                IsMarried = e.IsMarried,
                Gender = e.Gender,
            }).ToListAsync();
            return View(await eF_Core_DbContext); 
        }

        // GET: Employees/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            //var employee = await _context.Employees     // can work with entity Model but may leak Sensitive data
            //    .FirstOrDefaultAsync(m => m.EmpId == id);

            var employeeVM= await _context.Employees.Select(e => new EmployeeViewModel
            {
                EmpId = e.EmpId,
                FullName = e.FullName,
                Address = e.Address,
                Phone = e.Phone,
                IsMarried = e.IsMarried,
                Gender = e.Gender,
            }).SingleOrDefaultAsync(e => e.EmpId == id);    // if found exactly one matches (as EmpId is PK)

            if (employeeVM == null)
            {
                return NotFound();
            }

            return View(employeeVM);
        }

        // GET: Employees/Create
        public IActionResult Create()
        {
            return View();
        }

        // POST: Employees/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("EmpId,FullName,Address,Phone,IsMarried,Gender")] EmployeeViewModel employeeVM)
        { 
            // Without [Bind], all public properties of Employee can be updated via the request.
            // With[Bind("Prop1,Prop2")], only those listed properties will be set; the rest are ignored.
            if (ModelState.IsValid)
            {
                // map ViewModel to Entity Model
                var employee = new Employee     
                {
                    EmpId = employeeVM.EmpId,
                    FullName = employeeVM.FullName,
                    Address = employeeVM.Address,
                    Phone = employeeVM.Phone,
                    IsMarried = employeeVM.IsMarried,
                    Gender = employeeVM.Gender,
                    };  // Parent navigation is optional (as some employee may be single)
                
                _context.Add(employee);     // add to database
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            return View();
        }

        // GET: Employees/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            //var employee = await _context.Employees.FindAsync(id);    Quickly fetch an entity by its primary key. (checks memory tracking cache)
            /* FindAsync = only for EF-tracked entities (models in DbSet<>).
             A ViewModel is not tracked by EF Core because it’s just a plain C# class used to carry data to/from the UI 
            — it doesn’t map directly to a database table, and it has no concept of a primary key inside EF.*/
            var employeeVM = await _context.Employees.Select(e => new EmployeeViewModel
            {
                EmpId = e.EmpId,
                FullName = e.FullName,
                Address = e.Address,
                Phone = e.Phone,
                IsMarried = e.IsMarried,
                Gender = e.Gender,
            }).SingleOrDefaultAsync(e => e.EmpId == id);    // can't use 

            if (employeeVM == null)
            {
                return NotFound();
            }
            return View(employeeVM);
        }

        // POST: Employees/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("EmpId,FullName,Address,Phone,IsMarried,Gender")] EmployeeViewModel employeeVM)
        {
            if (id != employeeVM.EmpId)
            {
                return NotFound();
            }

            var employee = new Employee
            {
                EmpId = employeeVM.EmpId,
                FullName = employeeVM.FullName,
                Address = employeeVM.Address,
                Phone = employeeVM.Phone,
                IsMarried = employeeVM.IsMarried,
                Gender = employeeVM.Gender,
            };
            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(employee);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!EmployeeExists(employee.EmpId))
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
            return View(employee);
        }

        // GET: Employees/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var employee = await _context.Employees.Select(e => new EmployeeViewModel
            {
                EmpId = e.EmpId,
                FullName = e.FullName,
                Address = e.Address,
                Phone = e.Phone,
                IsMarried = e.IsMarried,
                Gender = e.Gender,
            })
                .FirstOrDefaultAsync(m => m.EmpId == id);
            if (employee == null)
            {
                return NotFound();
            }

            return View(employee);
        }

        // POST: Employees/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var employee = await _context.Employees.FindAsync(id);
            if (employee != null)
            {
                _context.Employees.Remove(employee);
            }

            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool EmployeeExists(int id)
        {
            return _context.Employees.Any(e => e.EmpId == id);
        }
    }
}

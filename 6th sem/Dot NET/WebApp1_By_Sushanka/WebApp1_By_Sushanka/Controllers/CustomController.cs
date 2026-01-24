using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;
using WebApp1_By_Sushanka.Models;

namespace WebApp1_By_Sushanka.Controllers
{
    public class CustomController : Controller
    {
        public IActionResult MyRazorPage()
        {
            ViewBag.Name = "Sushanka";
            ViewBag.RollNo = 84;
            ViewBag.TableOf = ViewBag.RollNo + 1;
            ViewBag.Datetime = DateTime.Now;

            return View();
        }

        //[HttpGet]  no need as "GET" by default
        public IActionResult StudentForm()
        {
            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]     // protects form Cross-Site Request Forgery(CSRF) attacks
        public IActionResult FormSubmission(Student std)
        {
            if (ModelState.IsValid)
            {
                TempData["Student"] = JsonConvert.SerializeObject(std);  // Pass data between requests, e.g., after RedirectToAction
                return RedirectToAction("StudentDetail");   // sendig data via get request expose the sensitive data
            }
            return View();
        }

        //[HttpPost]
        public IActionResult StudentDetail()
        {            
            //var student_JSON = TempData["Student"] as string;     will kepp data for one request only777
            var student_JSON = TempData.Peek("Student") as string;      // TempData.Keep("Student") will preserve the value only for the next request after it's accessed.
            Student? student = JsonConvert.DeserializeObject<Student>(student_JSON); 

            //ViewBag.student = student; // viewbag can be used also

            return View("StudentDetail", student);   
        }
    }
}

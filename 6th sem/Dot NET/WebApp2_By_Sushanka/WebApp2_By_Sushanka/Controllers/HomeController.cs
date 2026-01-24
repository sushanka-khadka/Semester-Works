using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;
using WebApp2_By_Sushanka.Models;

namespace WebApp2_By_Sushanka.Controllers
{
    public class HomeController : Controller
    {
        // without dependency injection
        public JsonResult Index()
        {
            StudentRepository _studentRepository = new ();
            List<Student> allStudentDetails = _studentRepository.GetAllStudent();
            return Json(allStudentDetails);
        }

        public JsonResult GetStudentDetails(int id)
        {
            StudentRepository _studentRepository = new ();
            Student studentDetails = _studentRepository.GetStudentById(id);
            return Json(studentDetails);
        }
    }
}

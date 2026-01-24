using Microsoft.AspNetCore.Mvc;
using WebApp2_By_Sushanka.Models;

namespace WebApp2_By_Sushanka.Controllers
{
    public class DI_ActionController : Controller
    {
        // instance must be of interface for loose coupling
        public JsonResult Index([FromServices] IStudentRepository _studentRepository)
        {
            List<Student> allStudentDetails = _studentRepository.GetAllStudent();
            return Json(allStudentDetails);
        }
        public JsonResult GetStudentDetails(int id, [FromServices] IStudentRepository _studentRepository)
        {
            Student studentDetails = _studentRepository.GetStudentById(id);
            return Json(studentDetails);
        }
    }
}

using Microsoft.AspNetCore.Mvc;
using WebApp2_By_Sushanka.Models;

namespace WebApp2_By_Sushanka.Controllers
{
    public class DI_PropertyController : Controller
    {
        [FromServices]
        public IStudentRepository _studentRepository {  get; set; }
        public JsonResult Index()
        {
            var allStudentDetails = _studentRepository.GetAllStudent();
            return Json(allStudentDetails);
        }

        public JsonResult GetStudentDetails (int id)
        {
            var studentDetails = _studentRepository.GetStudentById(id);
            return Json(studentDetails);
        }
    }
}

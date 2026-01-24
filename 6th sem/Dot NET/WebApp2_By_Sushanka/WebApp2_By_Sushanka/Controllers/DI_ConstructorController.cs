using Microsoft.AspNetCore.Mvc;
using WebApp2_By_Sushanka.Models;

namespace WebApp2_By_Sushanka.Controllers
{
    public class DI_ConstructorController : Controller
    {
        public readonly IStudentRepository _studentRepository;
        
        // Constructor Injection (DI)
        public DI_ConstructorController(IStudentRepository studentRepository)
        {
            _studentRepository = studentRepository;
        }
        public JsonResult Index()
        {
            List<Student> allStudentDetails = _studentRepository.GetAllStudent();
            return Json(allStudentDetails);
        }

        public JsonResult GetStudentDetails (int id)
        {
            Student studentDetails = _studentRepository.GetStudentById(id);
            return Json(studentDetails);
        }
    }
}

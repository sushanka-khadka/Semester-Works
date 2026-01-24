namespace WebApp2_By_Sushanka.Models
{
    public interface IStudentRepository
    {
        List<Student> GetAllStudent();
        Student GetStudentById(int StudentId);
    }
}

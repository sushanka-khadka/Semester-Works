using System.Diagnostics.CodeAnalysis;

namespace WebApp2_By_Sushanka.Models
{
    public class StudentRepository : IStudentRepository
    {
        // all students data list
        public  List<Student> DataSource ()
        {
            return new List<Student>()      // can be declared as []
            {
                new Student() { StudentId = 101, Name = "James", Branch = "CSE", Section = "A", Gender = "Male" },
                new () { StudentId = 102, Name = "Smith", Branch = "ETC", Section = "B", Gender = "Male" },
                new () { StudentId = 103, Name = "David", Branch = "CSE", Section = "A", Gender = "Male" },
                new () { StudentId = 104, Name = "Sara", Branch = "CSE", Section = "A", Gender = "Female" },
                new () { StudentId = 105, Name = "Pam", Branch = "ETC", Section = "B", Gender = "Female" }
            };
        }

        public Student GetStudentById(int id)
        {
            return DataSource().FirstOrDefault(std => std.StudentId == id) ?? new Student();
        }

        public List<Student> GetAllStudent()
        {
            return DataSource();
        }
    }
}

using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using WebApi_By_Sushanka.Data;
using WebApi_By_Sushanka.Models;

namespace WebApi_By_Sushanka.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class StudentApiController(ApiDbContext context) : ControllerBase
    {
        private readonly ApiDbContext _context= context;

        // GET: api/students
        [HttpGet]
        public async Task<ActionResult<IEnumerable<Student>>> GetStudents()
        {
            return await _context.Students.ToListAsync();
        }
        
        // GET: api/students/3
        [HttpGet("{id}")]
        public async Task<ActionResult<Student>> GetStudent(int id)
        {
            var student = await _context.Students.FindAsync(id);
            if (student == null)
                return NotFound();
            return student;
        }

        // POST: api/students/3
        [HttpPost]
        public async Task<ActionResult<Student>> PostStudent(Student student)
        {
            student.Id = 0; // now EF knows it's a new entity
            _context.Students.Add(student);
            await _context.SaveChangesAsync();
            return CreatedAtAction(nameof(GetStudent), new { id = student.Id }, student);
        }

        // PUT: api/students/3
        [HttpPut("{id}")]
        public async Task<IActionResult> PutStudent(int id, Student student)
        {
            if (id != student.Id) return BadRequest();
            _context.Entry(student).State = EntityState.Modified;
            await _context.SaveChangesAsync();
            return NoContent();
        }

        // DELETE: api/students/3
        [HttpDelete("{id}")]
        public async Task<IActionResult> DeleteStudent(int id)
        {
            var student = await _context.Students.FindAsync(id);
            if (student == null) return NotFound();
            _context.Students.Remove(student);
            await _context.SaveChangesAsync();
            return NoContent(); 
        }
    }
}

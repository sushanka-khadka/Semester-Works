using EF_Core_DB_First.Models;
using Microsoft.EntityFrameworkCore;

namespace EF_Core_DB_First.Data
{
    public class EF_Core_DbContext(DbContextOptions<EF_Core_DbContext> options) : DbContext(options)
    {
        public DbSet<Employee> Employees { get; set; }
        public DbSet<Parent> Parents { get; set; }
        public DbSet <Child> Children { get; set; }
    }
}

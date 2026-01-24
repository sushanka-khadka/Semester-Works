using Microsoft.EntityFrameworkCore;
using System.Collections.Generic;
using WebApi_By_Sushanka.Models;

namespace WebApi_By_Sushanka.Data
{
    public class ApiDbContext(DbContextOptions<ApiDbContext> options) : DbContext(options)
    {
        public DbSet<Student> Students { get; set; }
    }
}

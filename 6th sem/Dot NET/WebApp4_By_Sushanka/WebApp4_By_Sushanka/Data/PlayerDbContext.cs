using Microsoft.EntityFrameworkCore;
using WebApp4_By_Sushanka.Models;

namespace WebApp4_By_Sushanka.Data
{
    public class PlayerDbContext(DbContextOptions<PlayerDbContext> options) : DbContext(options)
    {
        public DbSet<Player> Players { get; set; }
    }
}

using Microsoft.EntityFrameworkCore;

namespace WebApp5_By_Sushanka.Models;

public partial class WebApp5DbFirstContext : DbContext
{
    public WebApp5DbFirstContext()
    {
    }

    public WebApp5DbFirstContext(DbContextOptions<WebApp5DbFirstContext> options)
        : base(options)
    {
    }

    public virtual DbSet<Student> Students { get; set; }

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        => optionsBuilder.UseSqlServer("Name=conStr");

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder.Entity<Student>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PK__Students__3214EC07A394FE04");

            entity.Property(e => e.Name).HasMaxLength(100);
        });

        OnModelCreatingPartial(modelBuilder);
    }

    partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
}

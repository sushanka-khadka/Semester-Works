using Microsoft.EntityFrameworkCore;
using WebApp4_By_Sushanka.Data;
using WebApp4_By_Sushanka.Repositories;

namespace WebApp4_By_Sushanka
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var builder = WebApplication.CreateBuilder(args);

            // Add services to the container.
            builder.Services.AddControllersWithViews();
            
            // Add DbContext with SQL Server provider
            builder.Services.AddDbContext<PlayerDbContext>(options =>
                options.UseSqlServer(builder.Configuration.GetConnectionString("conStr")));
            // Register the repository using dependency injection
            builder.Services.AddScoped<IPlayerRepository, PlayerRepository>();  

            var app = builder.Build();

            // Configure the HTTP request pipeline.
            if (!app.Environment.IsDevelopment())
            {
                app.UseExceptionHandler("/Home/Error");
                // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
                app.UseHsts();
            }

            app.UseHttpsRedirection();
            app.UseRouting();

            app.UseAuthorization();

            app.MapStaticAssets();
            app.MapControllerRoute(
                name: "default",
                pattern: "{controller=Home}/{action=Index}/{id?}")
                .WithStaticAssets();

            app.Run();
        }
    }
}

using Microsoft.EntityFrameworkCore;
using System;
using WebApp7_By_Sushanka.Data;
using Microsoft.AspNetCore.Identity;
using System.Threading.Tasks;

namespace WebApp7_By_Sushanka
{
    public class Program
    {
        public static async Task Main(string[] args)
        {
            var builder = WebApplication.CreateBuilder(args);

            // Add services to the container.
            builder.Services.AddControllersWithViews();

            // 1. Add EF Core DbContext
            builder.Services.AddDbContext<AppDbContext>(options =>
                options.UseSqlServer(builder.Configuration.GetConnectionString("conStr")));

            //builder.Services.AddDefaultIdentity<IdentityUser>(options => 
            //options.SignIn.RequireConfirmedAccount = true)
            //    .AddEntityFrameworkStores<AppDbContext>();


            builder.Services.AddIdentity<IdentityUser, IdentityRole>(options =>
                options.SignIn.RequireConfirmedAccount = true)
                .AddEntityFrameworkStores<AppDbContext>()
                .AddDefaultUI()
                .AddDefaultTokenProviders();


            //builder.Services.AddAuthorization(options =>
            //{
            //    options.AddPolicy("AddminOnly", policy => policy.RequireRole("Admin"));
            //    options.AddPolicy("HR:Department", policy => policy.RequireClaim("Department", "HR"));
            //    options.AddPolicy("Over18", policy => policy.RequireClaim("Age", "18"));
            //});

            builder.Services.AddAuthorizationBuilder()
                .AddPolicy("AddminOnly", policy => policy.RequireRole("Admin"))
                .AddPolicy("HR:Department", policy => policy.RequireClaim("Department", "HR"))
                .AddPolicy("Over18", policy => policy.RequireClaim("Age", "18"));
            
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

            app.MapRazorPages();    // register razor pages (required for Identity)

            using (var scope = app.Services.CreateScope())
            {
                var services = scope.ServiceProvider;
                await DbInitializer.Initialize(services);
            }

            app.MapStaticAssets();
            app.MapControllerRoute(
                name: "default",
                pattern: "{controller=Home}/{action=Index}/{id?}")
                .WithStaticAssets();

            app.Run();
        }
    }
}

namespace Angular_React_App_By_Sushanka
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var builder = WebApplication.CreateBuilder(args);

            // Add services to the container.
            builder.Services.AddControllersWithViews();

            var app = builder.Build();

            // Configure the HTTP request pipeline.
            if (!app.Environment.IsDevelopment())
            {
                app.UseExceptionHandler("/Home/Error");
                // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
                app.UseHsts();
            }

            app.UseHttpsRedirection();

            // Serve Angular build files
            //app.UseDefaultFiles();   // looks for index.html in wwwroot
            app.UseStaticFiles();    // serves js/css/assets from wwwroot

            app.UseRouting();
            app.UseAuthorization();

            // Map API endpoints
            app.MapControllers();   // /api/* routes handled here

            // Map MVC routes
            app.MapControllerRoute(
                name: "default",
                pattern: "{controller=Home}/{action=Index}/{id?}");

            app.MapFallbackToFile("/angular/{*path:nonfile}", "angular/index.html");
            app.MapFallbackToFile("/react/{*path:nonfile}", "react/index.html");

            app.Run();
        }
    }
}

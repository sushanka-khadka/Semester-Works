using Microsoft.AspNetCore.Identity;

namespace WebApp7_By_Sushanka.Data
{
    public static class DbInitializer
    {
        public static async Task Initialize(IServiceProvider serviceProvider)
        {        
            var roleManager = serviceProvider.GetRequiredService<RoleManager<IdentityRole>>();
            var userManager = serviceProvider.GetRequiredService<UserManager<IdentityUser>>();

            string[] roles = [ "Admin", "User" ];

            foreach (var role in roles)
            {
                if (!await roleManager.RoleExistsAsync(role))
                    await roleManager.CreateAsync(new IdentityRole(role));
            }

            // Create default admin user
            var adminUser = await userManager.FindByEmailAsync("user@admin.com");
            if (adminUser == null)
            {
                adminUser = new IdentityUser { 
                    UserName = "user@admin.com",
                    Email = "user@admin.com", 
                    EmailConfirmed = true 
                };
                await userManager.CreateAsync(adminUser, "Admin@123");
            }

            // Assign role if not already in it
            if (!await userManager.IsInRoleAsync(adminUser, "Admin"))
                await userManager.AddToRoleAsync(adminUser, "Admin");
        }
    }
}

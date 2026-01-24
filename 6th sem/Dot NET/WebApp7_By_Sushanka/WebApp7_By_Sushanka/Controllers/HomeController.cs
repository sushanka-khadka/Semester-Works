using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using NuGet.Protocol.Plugins;
using System.Security.Claims;

namespace WebApp7_By_Sushanka.Controllers
{
    //[Authorize(Roles ="Admin")]    // only admin can manage users
    public class HomeController(UserManager<IdentityUser> userManager, RoleManager<IdentityRole> roleManager) : Controller
    {
        private readonly UserManager<IdentityUser> _userManager = userManager;
        private readonly RoleManager<IdentityRole> _roleManager = roleManager;

        // List all users with roles/claims/policies
        [Authorize(Roles ="Admin")]
        public async Task<IActionResult> ManageUsers()
        {
            var users = await _userManager.Users.ToListAsync();
            var model = new List<UserViewModel>();

            foreach (var user in users)
            {
                var roles = await _userManager.GetRolesAsync(user);
                var claims = await _userManager.GetClaimsAsync(user);

                // check policies manually
                bool isAdminPolicy = roles.Contains("Admin");
                bool isHRPolicy = claims.Any(c => c.Type == "Department" && c.Value == "HR");
                bool isOver18Policy = claims.Any(c => c.Type == "Age" && int.TryParse(c.Value, out var age) && age >= 18);

                model.Add(new UserViewModel
                {
                    UserId = user.Id,
                    Email = user.Email,
                    Roles = roles,
                    Claims = [..claims.Select(c => $"{c.Type} : {c.Value}")],
                    Policies = [
                        isAdminPolicy ? "RequireAdmin" : "",
                        isHRPolicy ? "HRPolicy" : "",
                        isOver18Policy ? "Over18" : ""
                    ]
                });
            }
            return View(model);
        }

        // Add Role
        [HttpPost]
        public async Task<IActionResult> AddRole(string userId, string role)
        {
            var user = await _userManager.FindByIdAsync(userId);
            if(user != null && await _roleManager.RoleExistsAsync(role))
                await _userManager.AddToRoleAsync(user, role);

            return RedirectToAction("ManageUsers");
        }

        // Remove Role
        [HttpPost]
        public async Task<IActionResult> RemoveRole(string userId, string role)
        {
            var user = await _userManager.FindByIdAsync(userId);
            if (user != null)
                await _userManager.RemoveFromRoleAsync(user, role);

            return RedirectToAction("ManageUsers");
        }

        // Add Claim 
        [HttpPost]
        public async Task<IActionResult> AddClaim(string userId, string type, string value)
        {
            var user = await _userManager.FindByIdAsync(userId);
            if (user != null)
                await _userManager.AddClaimAsync(user, new System.Security.Claims.Claim(type, value));

            return RedirectToAction("ManageUsers");
        }

        // Remove Claim 
        [HttpPost]
        public async Task<IActionResult> RemoveClaim(string userId, string type, string value)
        {
            var user = await _userManager.FindByIdAsync(userId);
            if (user != null)
                await _userManager.RemoveClaimAsync(user, new System.Security.Claims.Claim(type, value));

            return RedirectToAction("ManageUsers");
        }
        
        public IActionResult Index()
        {
            return View();
        }
        [Authorize] // any logged-in user
        public IActionResult UserPage()
        {
            return View();
        }

        [Authorize(Roles ="Admin")] // only Admin role
        public IActionResult AdminPage()
        {
            return View();
        }

        [AllowAnonymous]    // anyone can visit
        public IActionResult PublicPage()
        {
            return View();
        }
    }

    public class UserViewModel
    {
        public string UserId { get; set; } = null!;
        public string Email { get; set; } = null!;
        public IList<string> Roles { get; set; } = [];
        public IList<string> Claims { get; set; } = [];
        public IList<string> Policies { get; set; } = [];
    }
}

using System.Diagnostics;
using Microsoft.AspNetCore.Localization;
using Microsoft.AspNetCore.Mvc;
using WebApp6_By_Sushanka.Models;

namespace WebApp6_By_Sushanka.Controllers
{
    public class HomeController : Controller
    {
        // Dummy ceredentials
        private readonly string USERNAME = "admin";
        private readonly string PASSWORD = "123";
        
        public IActionResult Login()
        {
            // check if user already logged in; redirect to home/index
            if (HttpContext.Session.GetString("Username") != null)
            {
                return RedirectToAction("Index");                
            }

            if (Request.Cookies.ContainsKey("SavedUsername"))
            {
                ViewBag.SavedUsername = Request.Cookies["SavedUsername"];
            }

            return View();
        }

        [HttpPost]
        public IActionResult Login(string Username, string Password, bool rememberMe)   // razor and model binding are case insensitive
        {
            Console.WriteLine("Login POST called");
            foreach(var item in Request.Form.Keys)
            {
                Console.WriteLine($"{item} : {Request.Form[item]}");
            }
            Console.WriteLine($"Username: {Username}, Password: {Password}, savedUsername: {rememberMe}");
            if (Username == USERNAME && Password == PASSWORD)
            {
                // setting session
                HttpContext.Session.SetString("Username", Username);
                //HttpContext.Session.SetString("LoginTime", DateTime.Now.ToString("mm:ss"));
                HttpContext.Session.SetString("LoginTime", DateTime.Now.ToString("yyyy-MM-ddTHH:mm:ss"));

                if (rememberMe)
                {                    
                    Response.Cookies.Append("SavedUsername", Username, new CookieOptions
                    {
                        Expires = DateTime.Now.AddDays(7) // Cookie will expire in 7 days
                    });
                }
                else    // delete cookie if user uncheck the checkbox
                {
                    Response.Cookies.Delete("SavedUsername");
                }
                return RedirectToAction("Index");
            }
            else
            {
                ViewBag.Error = "Invalid Username or Password!!!";
                return View();
            }
        }

        public IActionResult Logout()
        {
            return View();
        }
        [HttpPost]
        public IActionResult LogOut()
        {
            // clear session
            HttpContext.Session.Clear();
            return RedirectToAction("Index");
        }

        public IActionResult Index()
        {
            if (HttpContext.Session.GetString("Username") == null)
            {
                return RedirectToAction("Login");
            }
            return View();
        }

        [HttpPost]
        public IActionResult Index(IFormCollection form)
        {
            var username = form["username"].ToString();
            CookieOptions options = new CookieOptions();
            options.Expires = DateTime.Now.AddSeconds(10);  // Cookie will expire in 10 seconds
            Response.Cookies.Append("username", username, options);
            //Response.Cookies.Append("Email", "User@gmail.com", new CookieOptions { Expires = DateTime.Now.AddSeconds(5) });
            return View();
        }


        public IActionResult GetCookies()
        {
            // Retrieving a cookie
            //ViewBag.CookieValue = Request.Cookies["username"] ?? "Cookie not found";        // shortcut of HttpContext.Request.Cookies
            TempData["CookieValue"] = Request.Cookies["username"] ?? "Cookie not found";        // shortcut of HttpContext.Request.Cookies
            //return View("Index");
            return RedirectToAction("Index");
        }
        
        public IActionResult DeleteCookies()
        {
            // Deleting a cookie
            Response.Cookies.Delete("username");
            TempData["CookieValue"]= "Cookie deleted";
            return RedirectToAction("Index");
        }

        public IActionResult GetUser(int id, string name, string role)
        {
            User newUser = new User()
            {
                Id = id,
                Name = name,
                Role = role,
            };
            if (Request.Cookies.ContainsKey("Username"))    // only logged in user can access this action
            {
                return View(newUser);
            }
            return RedirectToAction("Login");
        }
    }
}

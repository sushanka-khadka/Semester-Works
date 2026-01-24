using Microsoft.AspNetCore.Mvc;
using WebApp3_By_Sushanka.Models;

namespace WebApp3_By_Sushanka.Controllers
{
    public class CRUDController(IPlayerInfo player) : Controller    // constructor injection using primary constructor
    {
        private readonly IPlayerInfo _player = player;

        public IActionResult Index()
        {
            var players = _player.GetAllPlayers();
            return View(players);
        }

        public IActionResult ViewPlayer(int id)
        {
            var player = _player.GetPlayerById(id);
            return View(player);
        }

        [HttpGet]
        public IActionResult Addplayer()
        {
            ViewBag.Title = "Add Player";
            ViewBag.Action = "AddPlayer";
            ViewBag.Button = "Add";
                        
            return View();
        }

        [HttpPost]
        [AutoValidateAntiforgeryToken]
        public IActionResult AddPlayer(Player p)
        {            
            if (ModelState.IsValid)
            {
                _player.AddPlayer(p);

                TempData["SuccessMessage"] = "Player Added Successfully";                
                return RedirectToAction("Index");                
            }
            return Content("Failed to register player.");
        }

        [HttpGet]
        public IActionResult EditPlayer(int id)
        {
            var player = _player.GetPlayerById(id);
            if (player == null) return Content("No player found");
            
            ViewBag.Title = "Edit Player";
            ViewBag.Action = "EditPlayer";
            ViewBag.Button = "Update";
            return View(viewName:"Views/CRUD/AddPlayer.cshtml", model:player);
        }

        [HttpPost]
        [AutoValidateAntiforgeryToken]
        public IActionResult EditPlayer(Player p)
        {
            if (ModelState.IsValid)
            {
                _player.UpdatePlayer(p);

                TempData["SuccessMessage"] = "Player Updated Successfully";
                return RedirectToAction("Index");
            }
            return Content("Failed to update player");
        }

        public IActionResult DeletePlayer(int id)
        {
            _player.DeletePlayer(id);
            
            TempData["SuccessMessage"] = "Player deleted successfully!";
            return RedirectToAction("Index");
        }
    }
}

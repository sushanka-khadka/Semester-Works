using Microsoft.AspNetCore.Mvc;
using WebApp4_By_Sushanka.Models;
using WebApp4_By_Sushanka.Repositories;

namespace WebApp4_By_Sushanka.Controllers
{
    public class HomeController(IPlayerRepository playerRepository) : Controller
    {
        private readonly IPlayerRepository _player = playerRepository;
        public async Task<IActionResult> Index()
        {
            var players = await _player.GetAllPlayersAsync();
            return View(players);

        }

        public async Task<IActionResult> ViewPlayer(int id)
        {
            var player = await _player.GetPlayerByIdAsync(id);
            return View(player);
        }

        public IActionResult AddPlayer()
        {
            return View();
        }

        [HttpPost]
        [AutoValidateAntiforgeryToken]
        public async Task<IActionResult> AddPlayer(Player p)
        {
            if (ModelState.IsValid)
            {
                await _player.AddPlayerAsync(p);
                return RedirectToAction("Index");
            }
            return Content("Failed to register player.");
        }

        public async Task<IActionResult> EditPlayer(int id)
        {
            var player = await _player.GetPlayerByIdAsync(id);
            return View(player);
        }

        [HttpPost]
        [AutoValidateAntiforgeryToken]
        public async Task<IActionResult> EditPlayer(Player p)
        {
            if (ModelState.IsValid)
            {
                await _player.UpdatePlayerAsync(p);
                return RedirectToAction("Index");
            }
            return Content("Failed to update player");
        }

        public async Task<IActionResult> DeletePlayer(int id)
        {
            await _player.DeletePlayerAsync(id);
            return RedirectToAction("Index");
        }
    }
}

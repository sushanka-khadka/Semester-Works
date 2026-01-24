using WebApp4_By_Sushanka.Models;

namespace WebApp4_By_Sushanka.Repositories
{
    public interface IPlayerRepository
    {
        Task<List<Player>> GetAllPlayersAsync();
        Task<Player?> GetPlayerByIdAsync(int id);
        Task AddPlayerAsync(Player p);
        Task UpdatePlayerAsync(Player p);
        Task DeletePlayerAsync(int id);
    }
}

using Microsoft.EntityFrameworkCore;
using WebApp4_By_Sushanka.Data;
using WebApp4_By_Sushanka.Models;

namespace WebApp4_By_Sushanka.Repositories
{
    public class PlayerRepository(PlayerDbContext context) : IPlayerRepository
    {
        private readonly PlayerDbContext _context = context;
        public async Task<List<Player>> GetAllPlayersAsync()
        {
            return await _context.Players.ToListAsync();
        }

        
        public async Task<Player?> GetPlayerByIdAsync(int id)
        {
            return await _context.Players.FindAsync(id);
        }

        public async Task AddPlayerAsync(Player p)
        {
            await _context.Players.AddAsync(p);
            await _context.SaveChangesAsync();
        }

        public async Task UpdatePlayerAsync(Player p)
        {
            _context.Players.Update(p);
            await _context.SaveChangesAsync();
        }
        public async Task DeletePlayerAsync(int id)
        {
            var player = await _context.Players.FindAsync(id) ?? null;
            if (player == null) return;
            _context.Players.Remove(player);
            await _context.SaveChangesAsync();
        }
    }
}

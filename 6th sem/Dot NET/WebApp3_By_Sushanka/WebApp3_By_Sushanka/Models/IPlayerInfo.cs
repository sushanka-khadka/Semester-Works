namespace WebApp3_By_Sushanka.Models
{
    public interface IPlayerInfo
    {     
        List<Player> GetAllPlayers();
        Player GetPlayerById(int id);
        public void AddPlayer(Player p);
        public void UpdatePlayer(Player p);
        public void DeletePlayer(int id);

    }
}

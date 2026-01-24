using System.Configuration;
using Microsoft.Data.SqlClient;

namespace WebApp3_By_Sushanka.Models
{
    public class PlayerInfo : IPlayerInfo
    {
        readonly static string connectionString = "Data source=localhost; Initial Catalog =Player_WebDb; " +
                "Integrated Security = True; Encrypt=True; TrustServerCertificate=True";
        
        public List<Player> GetAllPlayers()
        {
            string query = "select * from players";
            using SqlConnection conn = new(connectionString);
            SqlCommand cmd = new(query, conn);
            conn.Open();

            SqlDataReader reader = cmd.ExecuteReader();

            List<Player> players = [];
            while (reader.Read())
            {
                players.Add(new Player()
                {
                    Id = Convert.ToInt32(reader["id"]),
                    Name = reader["Name"].ToString(),
                    Country = reader["Country"].ToString(),
                    Club = reader["Club"].ToString(),
                    Position = reader["Position"].ToString(),
                    Foot = reader["Foot"].ToString()
                });
            }
            return players;
        }

        public Player GetPlayerById(int id)
        {
            string query = "select * from players where Id=@id";
            using SqlConnection conn = new(connectionString);
            SqlCommand cmd = new(query, conn);
            cmd.Parameters.AddWithValue("@id", id);
            conn.Open();

            SqlDataReader reader = cmd.ExecuteReader();
            if (reader.Read())
            {
                Player player = new()
                {
                    Id = Convert.ToInt32(reader["id"]),
                    Name = reader["Name"].ToString(),
                    Country = reader["Country"].ToString(),
                    Club = reader["Club"].ToString(),
                    Position = reader["Position"].ToString(),
                    Foot = reader["Foot"].ToString()
                };
                return player;
            }
            return null;
        }

        public void AddPlayer(Player p)
        {
            string query = "insert into players values(@name, @country, @club, @position, @foot)";
            using SqlConnection conn = new(connectionString);
            SqlCommand cmd = new(query, conn);
            conn.Open();
            cmd.Parameters.AddWithValue("@name", p.Name);
            cmd.Parameters.AddWithValue("@country", p.Country != null ? p.Country : DBNull.Value);
            cmd.Parameters.AddWithValue("@club", p.Club != null ? p.Club : DBNull.Value);
            cmd.Parameters.AddWithValue("@position", p.Position != null ? p.Position : DBNull.Value);
            cmd.Parameters.AddWithValue("@foot", p.Foot);
            int rows = cmd.ExecuteNonQuery();
            //Console.WriteLine($"Affected rows: {rows}");
        }

        public void UpdatePlayer(Player p)
        {
            string query = "update Players set Name=@name, Country=@country, Club=@club, Position=@position, Foot=@foot where Id=@id";
            using SqlConnection conn = new(connectionString);
            SqlCommand cmd = new(query, conn);
            conn.Open();
            cmd.Parameters.AddWithValue("@id", p.Id);
            cmd.Parameters.AddWithValue("@name", p.Name);
            cmd.Parameters.AddWithValue("@country", p.Country != null ? p.Country : DBNull.Value);
            cmd.Parameters.AddWithValue("@club", p.Club != null ? p.Club : DBNull.Value);
            cmd.Parameters.AddWithValue("@position", p.Position != null ? p.Position : DBNull.Value);
            cmd.Parameters.AddWithValue("@foot", p.Foot);
            int rows = cmd.ExecuteNonQuery();
            //Console.WriteLine($"Affected rows: {rows}");            
        }
            
        public void DeletePlayer(int id)
        {
            string query = "delete from players where Id=@id";
            using SqlConnection conn = new(connectionString);
            SqlCommand cmd = new(query, conn);
            cmd.Parameters.AddWithValue("@id", id);
            conn.Open();

            int rows = cmd.ExecuteNonQuery();
            //Console.WriteLine($"Affected rows: {rows}");
        }
    }    
}

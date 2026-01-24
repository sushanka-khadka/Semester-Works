using Microsoft.Data.SqlClient;
using System;
using System.Data;

namespace ConsoleApp_Sushanka
{
    class CRUD
    {
        static readonly string connectionString = "Data source= localhost; Initial Catalog=PlayerDB; Integrated Security = True;" +
            "Encrypt=True; TrustServerCertificate=True";

        static void Main()
        {
            while (true)
            {
                Console.WriteLine("\n---------- Console App for CRUD Operation ----------");
                Console.Write($"1. Insert Player \n2. Read Players \n3. Update Player \n4. Delete Player \n5. Exit \nChoose an option: ");
                var option = Convert.ToInt32(Console.ReadLine());

                switch (option)
                {
                    case 1:
                        InsertPlayer();
                        break;
                    case 2:
                        ReadPlayers();
                        break;
                    case 3:
                        UpdatePlayer();
                        break;
                    case 4:
                        DeletePlayer();
                        break;
                    case 5:
                        Console.WriteLine("Exiting Program...");
                        Environment.Exit(0);
                        break;
                    default:
                        Console.WriteLine("Invalid option!!!");
                        break;
                }
            }
        }

        static void InsertPlayer()
        {
            Console.Write("Enter Player Name: ");
            string name = Console.ReadLine();
            Console.Write("Enter Country : ");
            string? country = Console.ReadLine();
            Console.Write("Enter Club: ");
            string? club= Console.ReadLine();
            Console.Write("Enter Playing Postition: ");
            string? position= Console.ReadLine();
            Console.Write("Enter Preferred Foot : ");
            string foot= Console.ReadLine();

            // connecting to sb and executing query            
            using SqlConnection conn = new(connectionString);
            conn.Open();
            string query = "insert into Players (Name, Country, Club, Position, Foot) values(@name, @country, @club, @position, @foot)";
            SqlCommand cmd = new (query, conn);
            cmd.Parameters.AddWithValue("@name", name);
            cmd.Parameters.AddWithValue("@country", country);
            cmd.Parameters.AddWithValue("@club", club);
            cmd.Parameters.AddWithValue("@position", position);
            cmd.Parameters.AddWithValue("@foot", foot);
            cmd.ExecuteNonQuery();
            Console.WriteLine("Player inserted successfully!");
            
        }
        static void ReadPlayers()
        {
            using SqlConnection conn = new(connectionString);
            conn.Open();
            string query = "select * from players";
            SqlCommand cmd = new(query, conn);
            SqlDataReader reader = cmd.ExecuteReader();
            //Console.WriteLine($"ID:  \tName:  \tCountry:  \tClub:  \tPosition:  \tFoot:");
            Console.WriteLine("{0,-3} {1,-10} {2,-10} {3,-10} {4,-10} {5,-10}", "ID:", "Name:", "Country:", "Club:", "Position:",  "Foot:");
            while (reader.Read())
            {
                //Console.WriteLine($"ID: {reader["Id"]} Name: {reader["name"]} Country: {reader["country"]} Club: {reader["club"]} Position: {reader["position"]}Foot: {reader["foot"]}");
                //Console.WriteLine($"{reader["Id"]}    {reader["name"]} {reader["country"]} {reader["club"]} {reader["position"]} {reader["foot"]}");
                Console.WriteLine("{0,-3} {1,-10} {2,-10} {3,-10} {4,-10} {5,-10}", reader["Id"], reader["Name"], 
                    reader["Country"], reader["Club"], reader["Position"], reader["Foot"]);
            }   
        }
        static void UpdatePlayer()
        {
            //Console.Write("Enter details to update ohterwise leave blank.");
            Console.Write("Enter Player Id to update: ");
            int id= Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter New Name: ");
            string name = Console.ReadLine();
            Console.Write("Enter New Country : ");
            string? country = Console.ReadLine();
            Console.Write("Enter New Club: ");
            string? club = Console.ReadLine();
            Console.Write("Enter New Playing Postition: ");
            string? position = Console.ReadLine();
            Console.Write("Enter New Preferred Foot : ");
            string foot = Console.ReadLine();

            using SqlConnection conn = new(connectionString);
            conn.Open();
            string query = "update Players set Name=@name, Country=@country, Club=@club, Position=@position, Foot=@foot where Id=@id";
            SqlCommand cmd = new(query, conn);
            cmd.Parameters.AddWithValue("@id", id);
            cmd.Parameters.AddWithValue("@name", name);
            cmd.Parameters.AddWithValue("@country", country);
            cmd.Parameters.AddWithValue("@club", club);
            cmd.Parameters.AddWithValue("@position", position);
            cmd.Parameters.AddWithValue("@foot", foot);
            int rows = cmd.ExecuteNonQuery();
            if (rows > 0)
                Console.WriteLine("Player updated successfully!");
            else
                Console.WriteLine("Player not found!");
        }
        static void DeletePlayer()
        {
            Console.Write("Enter Player Id to delete: ");
            int id = Convert.ToInt32(Console.ReadLine());

            using SqlConnection conn = new(connectionString);
            conn.Open();
            string query = "delete from Players where Id=@id";
            SqlCommand cmd = new(query, conn);
            cmd.Parameters.AddWithValue("@id", id);
            int rows = cmd.ExecuteNonQuery();
            if (rows > 0)
                Console.WriteLine("Player deleted successfully!");
            else
                Console.WriteLine("Player not found!");
        }

    }
}

using System.ComponentModel.DataAnnotations;

namespace WebApp6_By_Sushanka.Models
{
    public class User
    {
        [Required]
        public int Id { get; set; }
        [Required]
        public string Name { get; set; }
        [Required]
        public string Role { get; set; }
    }
}

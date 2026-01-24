using System.ComponentModel.DataAnnotations;

namespace WebApp4_By_Sushanka.Models
{
    public class Player
    {
        [Key]
        public int Id { get; set; }
        [Required(ErrorMessage = "*required")]
        public string Name { get; set; } = "";
        public string? Country { get; set; }
        public string? Club { get; set; }
        public string? Position { get; set; }

        [Required(ErrorMessage = "*required")]
        public string Foot { get; set; } = "";

    }
}

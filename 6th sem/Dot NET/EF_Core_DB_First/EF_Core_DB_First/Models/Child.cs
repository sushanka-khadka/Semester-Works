using System.ComponentModel.DataAnnotations;

namespace EF_Core_DB_First.Models
{
    public class Child
    {
        [Key]
        public int Id { get; set; }
        [Required]
        [StringLength(50)]
        public string Name { get; set; }
        [RegularExpression(@"Male|Female", ErrorMessage = "Gender is either Male or Female.")]
        public string Gender { get; set; }

        // no foregin key in main table as it is stored in join table
        // many to many navigation property (handled by EF Core join table)
        public ICollection<Parent> Parents { get; set; }
    }
}

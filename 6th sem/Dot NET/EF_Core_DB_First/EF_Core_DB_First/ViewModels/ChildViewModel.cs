using System.ComponentModel.DataAnnotations;

namespace EF_Core_DB_First.ViewModels
{
    public class ChildViewModel
    {
        [Key]
        public int Id { get; set; }
        [Required]
        [StringLength(50)]
        public string Name { get; set; }
        [RegularExpression(@"Male|Female", ErrorMessage = "Gender is either Male or Female.")]
        public string Gender { get; set; }
    }
}

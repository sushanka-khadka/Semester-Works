using System.ComponentModel.DataAnnotations;

namespace EF_Core_DB_First.Models
{
    public class Employee
    {
        [Key]
        public int EmpId { get; set; }
        [Required]
        [StringLength(50)]
        public string FullName { get; set; }
        [Required]
        [StringLength(50)]
        public string Address { get; set; }
        [Required]
        [StringLength(maximumLength:10, MinimumLength =10, ErrorMessage ="Phone number must be 10 digits.")]
        [RegularExpression(@"(98|97)\d{8}$", ErrorMessage ="Enter a valid Nepali Phone number.")]
        public string Phone { get; set; }
        [Required]
        public bool IsMarried { get; set; }
        [Required]
        [RegularExpression(@"Male|Female", ErrorMessage ="Gender is either Male or Female.")]
        public string Gender { get; set; }

        // navigation property 
        public Parent Parent { get; set; }
    }
}

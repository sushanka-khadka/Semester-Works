using System.ComponentModel.DataAnnotations;

namespace WebApp1_By_Sushanka.Models
{
    public class Student
    {        
        [Key]
        public int StdId{ get; set; }

        [Required(ErrorMessage = "Don't you have name?")]
        [MaxLength(20, ErrorMessage ="Are you writing essay?")]
        public string Name{ get; set; } = string.Empty;

        [Required(ErrorMessage ="Don't you exist?")]
        [StringLength(100)]
        public string Address { get; set; } = string.Empty;

        //[Required(ErrorMessage ="*Required")]
        [RegularExpression("^(Science|Management|Humanities|Education)$", 
            ErrorMessage ="Faculty must be Science, Management, Humanities or Education")]
        public string Faculty { get; set; } = "";
        
        [Range(16,70, ErrorMessage ="Take Social Security Allowance and chill.")]        
        public int Age { get; set; }

        [EmailAddress(ErrorMessage = "Invalid Email Address")]
        public string Email { get; set; } = "";
    }
}

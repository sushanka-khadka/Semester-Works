using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace EF_Core_DB_First.Models
{
    public class Parent
    {
        [Key]
        public int ParentId { get; set; }
        [Required]
        [StringLength(50)]
        public string Name { get; set; }
        public int HasChildren { get; set; }

        // foreign key to employee
        [ForeignKey("Employee")]
        public int EmpId { get; set; }
        // navigation property
        public Employee Employee { get; set; }
        
        // navigation property for children (many - many)
        public ICollection<Child> Children { get; set; }
    }
}

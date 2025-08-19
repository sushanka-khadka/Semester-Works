using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace EF_Core_DB_First.Models
{
    public class Parent
    {
        [Key]
        public int Id { get; set; }
        [Required]
        [StringLength(50)]
        public string Name { get; set; }
        public int hasChildren { get; set; }

        // foreign key to employee
        [ForeignKey("Employee")]
        public int EmpId { get; set; }
        // navigation property
        public Employee Employee { get; set; }
        [Required]

        // navigation property for children (many - many)
        public ICollection<Child> Children { get; set; }
    }
}

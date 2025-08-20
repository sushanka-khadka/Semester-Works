using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace EF_Core_DB_First.ViewModels
{
    public class ParentViewModel
    {
        [Key]
        public int Id { get; set; }
        [Required]
        [StringLength(50)]
        public string Name { get; set; }
        public int HasChildren { get; set; }

        // foreign key to employee
        [ForeignKey("Employee")]
        public int EmpId { get; set; }
        
        // no navigation property as this is ViewModel
    }
}

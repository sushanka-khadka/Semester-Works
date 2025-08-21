using Microsoft.AspNetCore.Mvc.Rendering;
using System.ComponentModel.DataAnnotations;

namespace EF_Core_DB_First.ViewModels
{
    public class ChildViewModel
    {
        [Key]
        public int ChildId { get; set; }
        [Required]
        [StringLength(50)]
        public string Name { get; set; }
        [RegularExpression(@"Male|Female", ErrorMessage = "Gender is either Male or Female.")]
        public string Gender { get; set; }

        // selected parentIds from dropdown/multiselect
        public List<int> SelectedParentIds { get; set; }
        // selected list items
        public List<SelectListItem> AvailableParents { get; set; }
    }
}

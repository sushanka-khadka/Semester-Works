using EF_Core_DB_First.Models;
using EF_Core_DB_First.ViewModels;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using NuGet.Protocol;

namespace EF_Core_DB_First.Extenstions
{
    public static class EntityViewModelExtension
    {
        // Employee -> EmployeeViewModel
        public static EmployeeViewModel ToViewModel (this Employee e)
        {
            return new EmployeeViewModel
            {
                EmpId = e.EmpId,
                FullName = e.FullName,
                Address = e.Address,
                Phone = e.Phone,
                IsMarried = e.IsMarried,
                Gender = e.Gender,
            };
        }

        // Parent -> ParentViewModel
        public static ParentViewModel ToViewModel(this Parent p)
        {
            return new ParentViewModel
            {
                ParentId = p.ParentId,
                Name = p.Name,
                HasChildren = p.HasChildren,
                EmpId = p.EmpId,
            };
        }

        // Child -> ChildViewModel
        public static ChildViewModel ToViewModel(this Child c)
        {
            return new ChildViewModel
            {
                ChildId = c.ChildId,
                Name = c.Name,
                Gender = c.Gender,
            };
        }
    }
}
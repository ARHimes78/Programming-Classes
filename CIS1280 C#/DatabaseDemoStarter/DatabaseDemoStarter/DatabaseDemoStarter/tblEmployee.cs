//------------------------------------------------------------------------------
// <auto-generated>
//    This code was generated from a template.
//
//    Manual changes to this file may cause unexpected behavior in your application.
//    Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace DatabaseDemoStarter
{
    using System;
    using System.Collections.Generic;
    
    public partial class tblEmployee
    {
        public tblEmployee()
        {
            this.tblDepartments = new HashSet<tblDepartment>();
            this.tblEmployees1 = new HashSet<tblEmployee>();
        }
    
        public int pkEmployeeID { get; set; }
        public Nullable<int> fkSupervisorID { get; set; }
        public string Name { get; set; }
        public string website { get; set; }
    
        public virtual ICollection<tblDepartment> tblDepartments { get; set; }
        public virtual ICollection<tblEmployee> tblEmployees1 { get; set; }
        public virtual tblEmployee tblEmployee1 { get; set; }
    }
}

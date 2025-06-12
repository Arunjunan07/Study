class Employee {
    constructor(public id: number, public name: string, public salary: number) {}
  
    displayDetails(): void {
      console.log("ID: " + this.id + ", Name: " + this.name + ", Salary: " + this.salary);
    }
  
    calculateSalary(): number {
      return this.salary;
    }
  }
  
  class FullTimeEmployee extends Employee {
    constructor(id: number, name: string, public monthlySalary: number) {
      super(id, name, monthlySalary);
    }
  
    calculateSalary(): number {
      return this.monthlySalary;
    }
  
    displayDetails(): void {
      console.log("ID: " + this.id + ", Name: " + this.name + ", Monthly Salary: " + this.monthlySalary);
    }
  }
  
  class PartTimeEmployee extends Employee {
    constructor(
      id: number,
      name: string,
      public hourlyWage: number,
      public hoursWorked: number
    ) {
      super(id, name, 0);
    }
  
    calculateSalary(): number {
      this.salary = this.hourlyWage * this.hoursWorked;
      return this.salary;
    }
  
    displayDetails(): void {
      console.log(
        "ID: " + this.id +
        ", Name: " + this.name +
        ", Hourly Wage: " + this.hourlyWage +
        ", Hours Worked: " + this.hoursWorked +
        ", Salary: " + this.calculateSalary()
      );
    }
  }
  
  // Example usage:
  const fullTimeEmployee = new FullTimeEmployee(1, "Alice", 5000);
  const partTimeEmployee = new PartTimeEmployee(2, "Bob", 20, 160);
  
  fullTimeEmployee.displayDetails();
  console.log("Full Time Salary: $" + fullTimeEmployee.calculateSalary());
  
  partTimeEmployee.displayDetails();
  console.log("Part Time Salary: $" + partTimeEmployee.calculateSalary());
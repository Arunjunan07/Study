interface IEmployee {
    id: number;
    name: string;
    department: string;
}


class Employee implements IEmployee{
    
    constructor(id: number, name: string, department: string) {
        this.id = id;
        this.name = name;
        this.department = department;
    }
    id: number;
    name: string;
    department: string;

    display(): void {
        console.log(`ID: ${this.id}, Name: ${this.name}, Department: ${this.department}`);
    }
}

class EmployeeManager {
    private employees: Employee[] = [];

    add(employee: Employee): void {
        this.employees.push(employee);
        console.log(`Employee ${employee.name} added successfully.`);
    }

    list(): void {
        console.log("Employee List:");
        this.employees.forEach(employee => employee.display());
    }
}

// Example Usage
const manager = new EmployeeManager();
const emp1 = new Employee(1, "Alice", "Engineering");
const emp2 = new Employee(2, "Bob", "Marketing");

manager.add(emp1);
manager.add(emp2);

manager.list();

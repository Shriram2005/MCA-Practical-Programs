/* Program for Employee, Professor and Staff with polymorphism and exception handling */

class InvalidDataException extends Exception {
    public InvalidDataException(String msg) { super(msg); }
}

class Employee {
    protected int empId;
    protected String name;
    protected double salary;

    public Employee(int empId, String name, double salary) throws InvalidDataException {
        if (empId <= 0) throw new InvalidDataException("Invalid Employee ID.");
        if (salary < 0) throw new InvalidDataException("Salary cannot be negative.");
        this.empId = empId;
        this.name = name;
        this.salary = salary;
    }

    public void displayDetails() {
        System.out.println("Employee ID   : " + empId);
        System.out.println("Name          : " + name);
        System.out.println("Salary        : " + salary);
    }
}

class Professor extends Employee {
    private String department;
    private String researchInterests;

    public Professor(int empId, String name, double salary, String department, String researchInterests) throws InvalidDataException {
        super(empId, name, salary);
        this.department = department;
        this.researchInterests = researchInterests;
    }

    @Override
    public void displayDetails() {
        System.out.println("---- Professor ----");
        super.displayDetails();
        System.out.println("Department    : " + department);
        System.out.println("Research Int. : " + researchInterests);
    }
}

class Staff extends Employee {
    private String designation;
    private int yearsOfService;

    public Staff(int empId, String name, double salary, String designation, int yearsOfService) throws InvalidDataException {
        super(empId, name, salary);
        if (yearsOfService < 0) throw new InvalidDataException("Years of service cannot be negative.");
        this.designation = designation;
        this.yearsOfService = yearsOfService;
    }

    @Override
    public void displayDetails() {
        System.out.println("---- Staff ----");
        super.displayDetails();
        System.out.println("Designation    : " + designation);
        System.out.println("Years of Svc   : " + yearsOfService);
    }
}

public class EmployeeManagement {
    public static void main(String[] args) {
        Employee[] employees = new Employee[3];
        try {
            employees[0] = new Professor(101, "Dr. A. Sharma", 120000.0, "Computer Science", "AI, Machine Learning");
            employees[1] = new Staff(201, "Mrs. B. Patel", 45000.0, "Lab Assistant", 5);
            employees[2] = new Professor(102, "Dr. C. Rao", 135000.0, "Physics", "Quantum Optics");
        } catch (InvalidDataException e) {
            System.err.println("Error creating employee: " + e.getMessage());
            return;
        }

        for (Employee e : employees) {
            e.displayDetails();
            System.out.println();
        }
    }
}

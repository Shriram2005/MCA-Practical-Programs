class Employee {
  constructor(name, department, salary) {
    this.name = name;
    this.department = department;
    this.salary = salary;
  }

  isEligibleForBonus() {
    return this.salary > 50000;
  }
}

const employees = [
  new Employee("Amit", "IT", 65000),
  new Employee("Neha", "HR", 45000),
  new Employee("Rohan", "Finance", 55000),
  new Employee("Priya", "Sales", 48000),
];

const eligibleEmployees = employees.filter((emp) => emp.isEligibleForBonus());

console.log("Employees Eligible for Bonus (Salary > 50,000):");
eligibleEmployees.forEach((emp) => {
  console.log(`${emp.name} (${emp.department}) - Rs. ${emp.salary}`);
});


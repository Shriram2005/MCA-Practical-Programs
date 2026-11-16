const fs = require("fs");
const path = require("path");

const inputFile = path.join(__dirname, "employees.txt");
const outputFile = path.join(__dirname, "salary_report.txt");

// Read employee details from file
const data = fs.readFileSync(inputFile, "utf-8").trim().split("\n");

let report = "Name | Department | Basic Salary | Bonus (10%) | Net Salary\n";
report += "------------------------------------------------------------\n";

data.forEach((line) => {
  const [name, dept, salaryStr] = line.trim().split(",");
  const salary = Number(salaryStr);
  const bonus = salary * 0.1;
  const netSalary = salary + bonus;

  report += `${name} | ${dept} | ${salary} | ${bonus} | ${netSalary}\n`;
});

// Write updated salary report to new file
fs.writeFileSync(outputFile, report);

console.log("Salary report generated successfully:\n");
console.log(report);


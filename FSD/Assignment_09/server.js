const express = require("express");
const app = express();

app.use(express.json());

let employees = [
  { id: 1, name: "Amit", department: "IT", salary: 55000 },
  { id: 2, name: "Neha", department: "HR", salary: 45000 },
];
let nextId = 3;

// READ ALL - GET /employees
app.get("/employees", (req, res) => {
  res.json(employees);
});

// READ ONE - GET /employees/:id
app.get("/employees/:id", (req, res) => {
  const emp = employees.find((e) => e.id === Number(req.params.id));
  if (!emp) return res.status(404).json({ error: "Employee not found" });
  res.json(emp);
});

// CREATE - POST /employees
app.post("/employees", (req, res) => {
  const { name, department, salary } = req.body;
  const newEmp = { id: nextId++, name, department, salary };
  employees.push(newEmp);
  res.status(201).json(newEmp);
});

// UPDATE - PUT /employees/:id
app.put("/employees/:id", (req, res) => {
  const emp = employees.find((e) => e.id === Number(req.params.id));
  if (!emp) return res.status(404).json({ error: "Employee not found" });

  const { name, department, salary } = req.body;
  if (name !== undefined) emp.name = name;
  if (department !== undefined) emp.department = department;
  if (salary !== undefined) emp.salary = salary;

  res.json(emp);
});

// DELETE - DELETE /employees/:id
app.delete("/employees/:id", (req, res) => {
  const index = employees.findIndex((e) => e.id === Number(req.params.id));
  if (index === -1) return res.status(404).json({ error: "Employee not found" });

  const deleted = employees.splice(index, 1);
  res.json({ message: "Employee deleted", employee: deleted[0] });
});

app.listen(3000, () => {
  console.log("Employee CRUD API running on http://localhost:3000");
});


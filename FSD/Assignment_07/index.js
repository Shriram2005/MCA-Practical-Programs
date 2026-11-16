const fs = require("fs");
const path = require("path");

const students = JSON.parse(
  fs.readFileSync(path.join(__dirname, "students.json"), "utf-8")
);

function getGrade(percentage) {
  if (percentage >= 75) return "A";
  if (percentage >= 60) return "B";
  if (percentage >= 40) return "C";
  return "Fail";
}

let topper = null;
let highestTotal = -1;
const subjectHighest = {};
const failedStudents = [];

console.log("=== Student Marks Report ===");

students.forEach((student) => {
  const subjects = Object.keys(student.marks);
  let total = 0;
  let hasFailed = false;

  subjects.forEach((sub) => {
    const score = student.marks[sub];
    total += score;

    if (score < 40) {
      hasFailed = true;
    }

    if (!subjectHighest[sub] || score > subjectHighest[sub].score) {
      subjectHighest[sub] = { name: student.name, score };
    }
  });

  const percentage = (total / (subjects.length * 100)) * 100;
  const grade = hasFailed ? "Fail" : getGrade(percentage);

  if (hasFailed) {
    failedStudents.push(student.name);
  }

  if (total > highestTotal) {
    highestTotal = total;
    topper = student.name;
  }

  console.log(
    `${student.name} | Total: ${total} | Percentage: ${percentage.toFixed(2)}% | Grade: ${grade}`
  );
});

console.log("\nClass Topper:", `${topper} (${highestTotal} marks)`);

console.log("\nSubject-wise Highest Marks:");
for (const sub in subjectHighest) {
  console.log(`${sub}: ${subjectHighest[sub].score} (${subjectHighest[sub].name})`);
}

console.log("\nStudents Failed in One or More Subjects:", failedStudents.join(", ") || "None");


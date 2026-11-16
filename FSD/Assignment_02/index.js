// Arrow function to determine Pass/Fail (pass if every subject >= 40)
const checkResult = (marks) => (marks.every((m) => m >= 40) ? "Pass" : "Fail");

// Function accepting any number of subject marks using rest parameters
function evaluateMarks(...marks) {
  let total = 0;

  marks.forEach((mark) => {
    total += mark;
  });

  const average = total / marks.length;
  const status = checkResult(marks);

  return {
    marks,
    total,
    average: Number(average.toFixed(2)),
    status,
  };
}

console.log("Student 1:", evaluateMarks(75, 80, 65, 90));
console.log("Student 2:", evaluateMarks(55, 32, 70));


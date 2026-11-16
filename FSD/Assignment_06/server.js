const http = require("http");

const loanSchemes = [
  { name: "Home Loan", rate: "8.5% p.a.", maxAmount: 5000000 },
  { name: "Car Loan", rate: "9.2% p.a.", maxAmount: 1500000 },
  { name: "Education Loan", rate: "7.5% p.a.", maxAmount: 2000000 },
  { name: "Personal Loan", rate: "11.5% p.a.", maxAmount: 500000 },
];

const server = http.createServer((req, res) => {
  const reqUrl = new URL(req.url, "http://localhost:3000");
  const pathname = reqUrl.pathname;

  res.setHeader("Content-Type", "application/json");

  if (pathname === "/") {
    res.writeHead(200);
    res.end(
      JSON.stringify(
        {
          message: "Welcome to Bank Loan Portal",
          routes: [
            "/schemes",
            "/emi?principal=100000&rate=10&months=12",
            "/eligibility?salary=40000&age=25",
          ],
        },
        null,
        2
      )
    );
  } else if (pathname === "/schemes") {
    res.writeHead(200);
    res.end(JSON.stringify({ loanSchemes }, null, 2));
  } else if (pathname === "/emi") {
    const P = Number(reqUrl.searchParams.get("principal")) || 100000;
    const annualRate = Number(reqUrl.searchParams.get("rate")) || 10;
    const N = Number(reqUrl.searchParams.get("months")) || 12;

    const R = annualRate / 12 / 100; // monthly interest rate
    const emi = (P * R * Math.pow(1 + R, N)) / (Math.pow(1 + R, N) - 1);

    res.writeHead(200);
    res.end(
      JSON.stringify(
        {
          principal: P,
          annualRate: `${annualRate}%`,
          months: N,
          monthlyEMI: Number(emi.toFixed(2)),
        },
        null,
        2
      )
    );
  } else if (pathname === "/eligibility") {
    const salary = Number(reqUrl.searchParams.get("salary")) || 40000;
    const age = Number(reqUrl.searchParams.get("age")) || 25;

    const eligible = salary >= 25000 && age >= 21 && age <= 60;

    res.writeHead(200);
    res.end(
      JSON.stringify(
        {
          salary,
          age,
          eligible,
          message: eligible
            ? "You are eligible for a bank loan."
            : "Not eligible (Need salary >= 25000 and age 21-60).",
        },
        null,
        2
      )
    );
  } else {
    res.writeHead(404);
    res.end(JSON.stringify({ error: "404 - Route Not Found" }, null, 2));
  }
});

server.listen(3000, () => {
  console.log("Bank Loan Portal running at http://localhost:3000");
});


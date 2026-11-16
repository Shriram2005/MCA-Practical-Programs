const bank = require("./bank");

console.log("Initial Balance: Rs.", bank.getBalance());

bank.deposit(2500);
console.log("Updated Balance: Rs.", bank.getBalance());

bank.withdraw(1200);
console.log("Updated Balance: Rs.", bank.getBalance());

bank.withdraw(5000); // Test insufficient balance
console.log("Final Balance: Rs.", bank.getBalance());


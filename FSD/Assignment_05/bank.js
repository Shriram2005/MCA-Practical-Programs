let balance = 1000; // Initial balance

function deposit(amount) {
  if (amount <= 0) {
    console.log("Deposit amount must be positive.");
    return balance;
  }
  balance += amount;
  console.log(`Deposited: Rs. ${amount}`);
  return balance;
}

function withdraw(amount) {
  if (amount <= 0) {
    console.log("Withdrawal amount must be positive.");
  } else if (amount > balance) {
    console.log("Insufficient balance!");
  } else {
    balance -= amount;
    console.log(`Withdrawn: Rs. ${amount}`);
  }
  return balance;
}

function getBalance() {
  return balance;
}

module.exports = { deposit, withdraw, getBalance };


import java.util.*;

class BankAccount {
    private static int counter = 1000;
    private int accountNumber;
    private String accountHolder;
    private double balance;

    BankAccount(String accountHolder, double initialBalance) {
        this.accountHolder = accountHolder;
        this.balance = initialBalance;
        this.accountNumber = counter++;
    }

    void deposit(double amount) {
        balance += amount;
        System.out.println("Deposited: " + amount + " | New Balance: " + balance);
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawn: " + amount + " | Remaining Balance: " + balance);
        } else {
            System.out.println("Insufficient balance!");
        }
    }

    void checkBalance() {
        System.out.println("Account No: " + accountNumber + " | Holder: " + accountHolder + " | Balance: " + balance);
    }

    int getAccountNumber() {
        return accountNumber;
    }
}

public class BankingApp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<BankAccount> accounts = new ArrayList<>();

        while (true) {
            System.out.println("\n--- Banking Application ---");
            System.out.println("1. Create Account");
            System.out.println("2. Deposit");
            System.out.println("3. Withdraw");
            System.out.println("4. Check Balance");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    sc.nextLine();
                    System.out.print("Enter name: ");
                    String name = sc.nextLine();
                    System.out.print("Enter initial balance: ");
                    double balance = sc.nextDouble();
                    BankAccount newAcc = new BankAccount(name, balance);
                    accounts.add(newAcc);
                    System.out.println("Account created successfully! Account No: " + newAcc.getAccountNumber());
                    break;

                case 2:
                    System.out.print("Enter account number: ");
                    int depAccNo = sc.nextInt();
                    System.out.print("Enter deposit amount: ");
                    double depAmount = sc.nextDouble();
                    boolean found = false;
                    for (BankAccount acc : accounts) {
                        if (acc.getAccountNumber() == depAccNo) {
                            acc.deposit(depAmount);
                            found = true;
                            break;
                        }
                    }
                    if (!found) System.out.println("Account not found!");
                    break;

                case 3:
                    System.out.print("Enter account number: ");
                    int withAccNo = sc.nextInt();
                    System.out.print("Enter withdrawal amount: ");
                    double withAmount = sc.nextDouble();
                    found = false;
                    for (BankAccount acc : accounts) {
                        if (acc.getAccountNumber() == withAccNo) {
                            acc.withdraw(withAmount);
                            found = true;
                            break;
                        }
                    }
                    if (!found) System.out.println("Account not found!");
                    break;

                case 4:
                    System.out.print("Enter account number: ");
                    int checkAccNo = sc.nextInt();
                    found = false;
                    for (BankAccount acc : accounts) {
                        if (acc.getAccountNumber() == checkAccNo) {
                            acc.checkBalance();
                            found = true;
                            break;
                        }
                    }
                    if (!found) System.out.println("Account not found!");
                    break;

                case 5:
                    System.out.println("Thank you for using the Banking Application!");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}

package Class;
public class Account {

    private final String accountOwner;
    private final String accountNumber;
    private double balance;

    public Account(String accountOwner, String accountNumber) {
        this.accountOwner = accountOwner;
        this.accountNumber = accountNumber;
    }

    public String getAccountOwner() {
        return accountOwner;
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public double getBalance() {
        return balance;
    }

    @Override
    public String toString() {
        return "Account{" +
                "accountOwner='" + accountOwner + '\'' +
                ", accountNumber='" + accountNumber + '\'' +
                ", balance=" + balance +
                '}';
    }

    public void deposit(double amount) {
        balance += amount;
    }

    public boolean transfer(Account a, double amount) {
        if (balance < amount) {
            return false;
        } else {
            balance -= amount;
            a.deposit(amount);
            return true;
        }
    }
}

#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;

public:
    void inputAccount() {
        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter balance: ";
        cin >> balance;
    }

    void displayAccount() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    void inputSavings() {
        inputAccount();
        cout << "Enter interest rate (%): ";
        cin >> interestRate;
    }

    void displaySavings() const {
        displayAccount();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    void inputCurrent() {
        inputAccount();
        cout << "Enter overdraft limit: ";
        cin >> overdraftLimit;
    }

    void displayCurrent() const {
        displayAccount();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    cout << "\n--- Savings Account Details ---\n";
    SavingsAccount s;
    s.inputSavings();
    s.displaySavings();

    cout << "\n--- Current Account Details ---\n";
    CurrentAccount c;
    c.inputCurrent();
    c.displayCurrent();

    return 0;
}

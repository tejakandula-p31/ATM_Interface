#include <iostream>
#include <string>
#include <iomanip> // For setting precision

using namespace std;

class ATM {
private:
    string accountHolderName;
    int pin;
    double balance;

    bool authenticate(int enteredPin) {
        return enteredPin == pin;
    }

public:
    ATM(string name, int pin, double initialBalance)
        : accountHolderName(name), pin(pin), balance(initialBalance) {}

    void showMenu() {
        cout << "\nWelcome, " << accountHolderName << "!\n";
        cout << "ATM Menu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
    }

    void checkBalance() const {
        cout << "Your current balance is: $" << fixed << setprecision(2) << balance << "\n";
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount. Please enter a positive value.\n";
        } else {
            balance += amount;
            cout << "Successfully deposited $" << fixed << setprecision(2) << amount << "\n";
            checkBalance();
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount. Please enter a positive value.\n";
        } else if (amount > balance) {
            cout << "Insufficient funds! Your current balance is $" << fixed << setprecision(2) << balance << "\n";
        } else {
            balance -= amount;
            cout << "Successfully withdrew $" << fixed << setprecision(2) << amount << "\n";
            checkBalance();
        }
    }

    void start() {
        int enteredPin;
        cout << "Enter your PIN to access the ATM: ";
        cin >> enteredPin;

        if (!authenticate(enteredPin)) {
            cout << "Invalid PIN. Access denied.\n";
            return;
        }

        int choice;
        do {
            showMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    checkBalance();
                    break;
                case 2: {
                    double depositAmount;
                    cout << "Enter amount to deposit: ";
                    cin >> depositAmount;
                    deposit(depositAmount);
                    break;
                }
                case 3: {
                    double withdrawAmount;
                    cout << "Enter amount to withdraw: ";
                    cin >> withdrawAmount;
                    withdraw(withdrawAmount);
                    break;
                }
                case 4:
                    cout << "Thank you for using the ATM. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    // Create an ATM account with a name, PIN, and initial balance
    ATM myATM("John Doe", 1234, 1000.00);

    // Start the ATM session
    myATM.start();

    return 0;
}


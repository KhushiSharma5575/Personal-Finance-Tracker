#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Transaction {
public:
    string description;
    double amount;
    string type; // "Income" or "Expense"

    Transaction(string desc, double amt, string t) {
        description = desc;
        amount = amt;
        type = t;
    }
};

class FinanceManager {
private:
    vector<Transaction> transactions;

public:
    void addTransaction() {
        string description, type;
        double amount;

        cout << "Enter description: ";
        cin.ignore();
        getline(cin, description);
        cout << "Enter amount: ";
        cin >> amount;
        cout << "Enter type (Income/Expense): ";
        cin >> type;

        transactions.push_back(Transaction(description, amount, type));
        cout << "Transaction added successfully!\n";
    }

    void showSummary() {
        double totalIncome = 0, totalExpense = 0;

        for (const auto &t : transactions) {
            if (t.type == "Income") {
                totalIncome += t.amount;
            } else if (t.type == "Expense") {
                totalExpense += t.amount;
            }
        }

        double netBalance = totalIncome - totalExpense;

        cout << "\nSummary of Finances\n";
        cout << "====================\n";
        cout << "Total Income: $" << fixed << setprecision(2) << totalIncome << endl;
        cout << "Total Expenses: $" << fixed << setprecision(2) << totalExpense << endl;
        cout << "Net Balance: $" << fixed << setprecision(2) << netBalance << endl;
    }
};

int main() {
    FinanceManager manager;
    int choice;

    do {
        cout << "\n1. Add Transaction\n2. View Summary\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            manager.addTransaction();
            break;
        case 2:
            manager.showSummary();
            break;
        case 3:
            cout << "Exiting... Goodbye!\n";
            break;
        default:
            cout << "Invalid choice, try again.\n";
        }
    } while (choice != 3);

    return 0;
}

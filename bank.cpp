#include <iostream>
using namespace std;
class Bankaccount
{
private:
    int accountNumber;
    string name;
    double balance;
    int pin;
    static int totalAccounts;

public:
    Bankaccount(int accNo, string n, double bal, int p)
    {
        accountNumber = accNo;
        name = n;
        balance = bal;
        pin = p;
        totalAccounts++;
    }
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Amount deposited successfully!\n";
        }
    }
    void withdraw(double amount, int enteredPin)
    {
        if (enteredPin == pin)
        {
            if (amount <= balance)
            {
                balance -= amount;
                cout << "withdrawal successful!\n";
            }
            else
            {
                cout << "Insufficient balance!\n";
            }
        }
        else
        {
            cout << "Incorrect PIN!\n";
        }
    }
    void display()
    {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }
    static int getTotalAccounts()
    {
        return totalAccounts;
    }
    friend void showAllAccounts(Bankaccount *Acc[], int size);
};
int Bankaccount::totalAccounts = 0;
void showAllAccounts(Bankaccount *acc[], int size)
{
    cout << "\n===== ADMIN  PANEL (ALL ACCOUNTS) =====\n";
    for (int i = 0; i < size; i++)
    {
        acc[i]->display();
        cout << "------------------------------\n";
    }
}
int main()
{
    int choice, n = 0;
    Bankaccount *accounts[100];
    while (true)
    {
        cout << "\n===== BANK MENU =====";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. withdraw Money";
        cout << "\n4. show Accouint Details";
        cout << "\n5. Admin: Show All Accounnts";
        cout << "\n6. Total Accounts";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            int accNo, pin;
            string name;
            double bal;

            cout << "Enter Account No: ";
            cin >> accNo;

            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Initial Balance: ";
            cin >> bal;

            cout << "Set PIN: ";
            cin >> pin;

            accounts[n] = new Bankaccount(accNo, name, bal, pin);
            n++;
            cout << "Account Created Successfully!\n";
        }
        else if (choice == 2)
        {
            int idx;
            double amt;

            cout << "Enter account index (0 to " << n - 1 << "): ";
            cin >> idx;

            cout << "Enter account deposit:";
            cin >> amt;

            if (idx >= 0 && idx < n)
                accounts[idx]->deposit(amt);
            else
                cout << "Invalid index!\n";
        }
        else if (choice == 3)
        {
            int idx, pin;
            double amt;

            cout << "Enter account  index: ";
            cin >> idx;

            cout << "Enter PIN: ";
            cin >> pin;

            cout << "Enter amount to Withdraw: ";
            cin >> amt;

            if (idx < n)
                accounts[idx]->withdraw(amt, pin);
        }
        else if (choice == 4)
        {
            int idx;
            cout << "Enter account index: ";
            cin >> idx;

            if (idx < n)
                accounts[idx]->display();
        }
        else if (choice == 5)
        {
            showAllAccounts(accounts, n);
        }
        else if (choice == 6)
        {
            cout << "Total Accounts: "
                 << Bankaccount::getTotalAccounts() << endl;
        }
        else if (choice == 0)
        {
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}

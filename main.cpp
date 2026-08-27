#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Account
{
public:
    int accountNumber;
    string name;
    double balance;

    void display()
    {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }
};

vector<Account> accounts;

// Load account data from file
void loadAccounts()
{
    ifstream file("accounts.txt");

    Account a;

    while (file >> a.accountNumber)
    {
        file.ignore();
        getline(file, a.name);
        file >> a.balance;

        accounts.push_back(a);
    }

    file.close();
}

// Save account data to file
void saveAccounts()
{
    ofstream file("accounts.txt");

    for (Account a : accounts)
    {
        file << a.accountNumber << endl;
        file << a.name << endl;
        file << a.balance << endl;
    }

    file.close();
}

// Create a new account
void createAccount()
{
    Account a;

    cout << "\nEnter Account Number: ";
    cin >> a.accountNumber;

    for (Account x : accounts)
    {
        if (x.accountNumber == a.accountNumber)
        {
            cout << "Account already exists.\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Customer Name: ";
    getline(cin, a.name);

    cout << "Enter Initial Balance: ";
    cin >> a.balance;

    if (a.balance < 0)
    {
        cout << "Balance cannot be negative.\n";
        return;
    }

    accounts.push_back(a);
    saveAccounts();

    cout << "Account created successfully.\n";
}

// Deposit money
void deposit()
{
    int number;
    double amount;

    cout << "\nEnter Account Number: ";
    cin >> number;

    for (Account &a : accounts)
    {
        if (a.accountNumber == number)
        {
            cout << "Enter amount to deposit: ";
            cin >> amount;

            if (amount <= 0)
            {
                cout << "Enter a valid amount.\n";
                return;
            }

            a.balance = a.balance + amount;
            saveAccounts();

            cout << "Money deposited successfully.\n";
            cout << "New Balance: " << a.balance << endl;

            return;
        }
    }

    cout << "Account not found.\n";
}

// Withdraw money
void withdraw()
{
    int number;
    double amount;

    cout << "\nEnter Account Number: ";
    cin >> number;

    for (Account &a : accounts)
    {
        if (a.accountNumber == number)
        {
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            if (amount <= 0)
            {
                cout << "Enter a valid amount.\n";
                return;
            }

            if (amount > a.balance)
            {
                cout << "Insufficient balance.\n";
                return;
            }

            a.balance = a.balance - amount;
            saveAccounts();

            cout << "Money withdrawn successfully.\n";
            cout << "Remaining Balance: " << a.balance << endl;

            return;
        }
    }

    cout << "Account not found.\n";
}

// Check balance
void checkBalance()
{
    int number;

    cout << "\nEnter Account Number: ";
    cin >> number;

    for (Account a : accounts)
    {
        if (a.accountNumber == number)
        {
            cout << "\nAccount Number: " << a.accountNumber;
            cout << "\nName: " << a.name;
            cout << "\nBalance: " << a.balance << endl;

            return;
        }
    }

    cout << "Account not found.\n";
}

// Display all accounts
void displayAccounts()
{
    if (accounts.empty())
    {
        cout << "\nNo accounts found.\n";
        return;
    }

    cout << "\n----- All Accounts -----\n";

    for (Account a : accounts)
    {
        a.display();
        cout << "------------------------\n";
    }
}

int main()
{
    loadAccounts();

    int choice;

    do
    {
        cout << "\n==============================";
        cout << "\n     BANK MANAGEMENT SYSTEM";
        cout << "\n==============================";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Check Balance";
        cout << "\n5. Display All Accounts";
        cout << "\n6. Exit";
        cout << "\n==============================";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createAccount();
            break;

        case 2:
            deposit();
            break;

        case 3:
            withdraw();
            break;

        case 4:
            checkBalance();
            break;

        case 5:
            displayAccounts();
            break;

        case 6:
            cout << "\nThank you for using the Bank Management System.\n";
            break;

        default:
            cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}

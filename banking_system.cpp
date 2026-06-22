#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Transaction Class
class Transaction
{
public:
    string type;
    double amount;

    Transaction(string t, double a)
    {
        type = t;
        amount = a;
    }

    void display()
    {
        cout << type << " : Rs." << amount << endl;
    }
};

// Account Class
class Account
{
private:
    int accountNumber;
    double balance;
    vector<Transaction> transactions;

public:
    Account(int accNo)
    {
        accountNumber = accNo;
        balance = 0;
    }

    int getAccountNumber()
    {
        return accountNumber;
    }

    double getBalance()
    {
        return balance;
    }

    void deposit(double amount)
    {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        cout << "Deposit Successful!\n";
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient Balance!\n";
            return;
        }

        balance -= amount;
        transactions.push_back(Transaction("Withdrawal", amount));
        cout << "Withdrawal Successful!\n";
    }

    bool transfer(Account &receiver, double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient Balance!\n";
            return false;
        }

        balance -= amount;
        receiver.balance += amount;

        transactions.push_back(Transaction("Transfer Sent", amount));
        receiver.transactions.push_back(Transaction("Transfer Received", amount));

        cout << "Transfer Successful!\n";
        return true;
    }

    void showTransactions()
    {
        if (transactions.empty())
        {
            cout << "No Transactions Found!\n";
            return;
        }

        cout << "\nTransaction History:\n";
        for (int i = 0; i < transactions.size(); i++)
        {
            transactions[i].display();
        }
    }
};

// Customer Class
class Customer
{
private:
    int customerID;
    string name;
    Account account;

public:
    Customer(int id, string n, int accNo)
        : account(accNo)
    {
        customerID = id;
        name = n;
    }

    int getCustomerID()
    {
        return customerID;
    }

    Account &getAccount()
    {
        return account;
    }

    void displayCustomer()
    {
        cout << "\nCustomer ID : " << customerID << endl;
        cout << "Name        : " << name << endl;
        cout << "Account No  : " << account.getAccountNumber() << endl;
        cout << "Balance     : Rs." << account.getBalance() << endl;
    }
};

int main()
{
    vector<Customer> customers;
    int choice;

    do
    {
        cout << "\n====== BANKING SYSTEM ======\n";
        cout << "1. Create Customer\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transfer Funds\n";
        cout << "5. View Account Details\n";
        cout << "6. View Transaction History\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id, accNo;
            string name;

            cout << "Enter Customer ID: ";
            cin >> id;

            cout << "Enter Customer Name: ";
            cin >> name;

            cout << "Enter Account Number: ";
            cin >> accNo;

            customers.push_back(Customer(id, name, accNo));

            cout << "Customer Created Successfully!\n";
            break;
        }

        case 2:
        {
            int id;
            double amount;

            cout << "Enter Customer ID: ";
            cin >> id;

            for (auto &c : customers)
            {
                if (c.getCustomerID() == id)
                {
                    cout << "Enter Amount: ";
                    cin >> amount;
                    c.getAccount().deposit(amount);
                }
            }
            break;
        }

        case 3:
        {
            int id;
            double amount;

            cout << "Enter Customer ID: ";
            cin >> id;

            for (auto &c : customers)
            {
                if (c.getCustomerID() == id)
                {
                    cout << "Enter Amount: ";
                    cin >> amount;
                    c.getAccount().withdraw(amount);
                }
            }
            break;
        }

        case 4:
        {
            int senderID, receiverID;
            double amount;

            cout << "Enter Sender Customer ID: ";
            cin >> senderID;

            cout << "Enter Receiver Customer ID: ";
            cin >> receiverID;

            cout << "Enter Amount: ";
            cin >> amount;

            Customer *sender = nullptr;
            Customer *receiver = nullptr;

            for (auto &c : customers)
            {
                if (c.getCustomerID() == senderID)
                    sender = &c;

                if (c.getCustomerID() == receiverID)
                    receiver = &c;
            }

            if (sender && receiver)
            {
                sender->getAccount().transfer(
                    receiver->getAccount(),
                    amount);
            }
            else
            {
                cout << "Customer Not Found!\n";
            }

            break;
        }

        case 5:
        {
            int id;

            cout << "Enter Customer ID: ";
            cin >> id;

            for (auto &c : customers)
            {
                if (c.getCustomerID() == id)
                {
                    c.displayCustomer();
                }
            }
            break;
        }

        case 6:
        {
            int id;

            cout << "Enter Customer ID: ";
            cin >> id;

            for (auto &c : customers)
            {
                if (c.getCustomerID() == id)
                {
                    c.getAccount().showTransactions();
                }
            }
            break;
        }

        case 7:
            cout << "Thank You for Using Banking System!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}
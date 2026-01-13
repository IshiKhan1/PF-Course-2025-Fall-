#include <iostream>
using namespace std;

double balance = 1000.0;

string username = "admin";
int pin = 1122;

void welcomeMessage()
{
    cout << "=============================" << endl;
    cout << "   BANK ACCOUNT SYSTEM" << endl;
    cout << "=============================" << endl;
}

bool login()
{
    string user;
    int enteredPin;

    cout<< "Enter username: ";
    cin>> user;

    cout<< "Enter pin: ";
    cin>> enteredPin;

    if(user == username && enteredPin == pin)
    {
        cout<< "Login successful!"<<endl;
        return true;
    }
    else{
        cout<< "Login failed! Inavalid username or pin."<<endl;
        return false;
    }
}
void depositMoney()
{
    double amount;

    cout << "Enter amount to deposit: ";
    cin >> amount;

    if (amount > 0)
    {
        balance = balance + amount;
        cout << "Deposit successful." << endl;
    }
    else
    {
        cout << "Invalid deposit amount." << endl;
    }

    cout << endl;
}

void withdrawMoney()
{
    double amount;

    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount > 0)
    {
        if (amount <= balance)
        {
            balance = balance - amount;
            cout << "Withdrawal successful." << endl;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }
    else
    {
        cout << "Invalid withdrawal amount." << endl;
    }

    cout << endl;
}

void checkBalance()
{
    cout << "Current Balance: Rs. " << balance << endl;
    cout << endl;
}

void takeLoan()
{
    double loanAmount;

    cout<< "Enter loan amount: ";
    cin>> loanAmount;

    if (loanAmount > 0)
    {
        balance = balance + loanAmount;
        cout<< "Loan Appproved successfully"<<endl;
    }
    else{
        cout<< "Invalid loanAmount"<<endl;
    }
    cout<< endl;
}

void showMenu()
{
    cout << "1. Deposit Money"<<endl;
    cout << "2. Withdraw Money"<<endl;
    cout << "3. Check Balance"<<endl;
    cout << "4. Take Loan"<<endl;
    cout << "5. Exit"<<endl;
}

int main()
{
    int choice;

    welcomeMessage();

    if (!login())
    {
        return 0;
    }
    do
    {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case 1:
                depositMoney();
                break;

            case 2:
                withdrawMoney();
                break;

            case 3:
                checkBalance();
                break;

                case 4:
                takeLoan();
                break;

            case 5:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

struct Date
{
    char day;
    string month;
    string year;
};

struct Transaction
{
    Date date;
    string name;
    double transamount;
    string fromAccount;
    string toAccount;
};

vector<Transaction> transactions;

void displaymainmenu()
{
    cout << "Transaction Menu" << "\n";
    cout << "1. Add Transaction" << "\n";
    cout << "2. Display Transaction" << "\n";
    cout << "3. Exit" << "\n";
}

bool check_month(const Date &date)
{
    string months_set[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Nov", "Dec"};

    if (date.day > 0 && date.day < 32)
    {
        for (string const& month : months_set)
        {
            if (month == date.month)
            {
                return true;
            }
        }
    }

    return false;
}

void title_transfer()
{
    cout << "Your Transfer Record" << "\n";
    cout << "--------------------" << "\n\n";
}

void from_to_account()
{
    Transaction trans;
    cout << "Day Date (DD-MMM-YYYY) : ";
    try
    {
        string temp;
        cin.ignore();
        getline(cin, temp);
        
        trans.date.day = stoi(temp.substr(0, 2));
        trans.date.month = temp.substr(3, 3);
        trans.date.year = temp.substr(7, 4);
    }
    catch(...)
    {
        std::cerr << "Something went wrong!" << "\n";
    }
 
    if (!check_month(trans.date))
    {
        cout << "Invalid month format. Use DD-MMM-YYYY (e.g., 28-May-2023)" << "\n";
        return;
    }
 
    cout << "Input Name: ";
    cin >> trans.name;
    cout << "Input Transfer Amount: ";
    cin >> trans.transamount;
    cout << "From Account: ";
    cin.ignore();
    getline(cin, trans.fromAccount);
    cout << "To Account: ";
    getline(cin, trans.toAccount);

    transactions.push_back(trans);
    cout << "New Transaction Added!" << "\n";
}

string construct_date(const Date &date)
{
    return to_string(static_cast<int>(date.day)) + "-" + date.month + "-" + date.year;
}

void display()
{
    if (transactions.empty())
    {
        cout << "No Transactions Found!" << endl;
    }
    cout << left << setw(20) << "Date" << setw(20) << "Name" << setw(30) << "Transfer Amount" << setw(30) << "From Account" << setw(20) << "To Account" << "\n";
    for (const Transaction &trans : transactions)
    {
        cout << left << setw(20) << construct_date(trans.date) << setw(20) << trans.name << setw(30) << trans.transamount << setw(30) << trans.fromAccount << setw(20) << trans.toAccount << "\n";
    }
}

int main()
{
    int g;
    do
    {
        displaymainmenu();
        cout << "Enter choice: ";
        cin >> g;

        switch (g)
        {
        case 1:
            from_to_account();
            break;
        case 2:
            display();
            break;
        case 3:
            cout << "Exit..." << "\n";
            break;
        default:
            cout << "Wrong input, try again!" << "\n";
            break;
        }
        cout << "\n";
    } while (g != 3);

    return 0;
}
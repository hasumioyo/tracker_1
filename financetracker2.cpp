#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct Transaction {
    string date;
    string name;
    double transamount;
    string fromAccount;
    string toAccount;
};

vector<Transaction> transactions;

void displaymainmenu(){
    cout << "Transaction Menu" << "\n";
    cout << "1. Add Transaction" << "\n";
    cout << "2. Display Transaction" << "\n";
    cout << "3. Exit" << "\n";

}

bool check_month(const string& date){
    vector<string>  months_set = {"-Jan-", "-Feb-", "-Mar-", "-Apr-", "-May-", "-Jun-", 
                                    "-Jul-", "-Aug-", "-Sep-", "-Nov-", "-Dec-"};
    vector<string>  day_set    = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", 
                                    "11", "12", "13", "14", "15", "16", "17", "18", "19", 
                                    "20","21", "22", "23", "24", "25", "26", "27", "28", "29", 
                                    "30", "31"};
    
    for (const string& day_sets : day_set){
        if (date.find(day_sets)!= string::npos){
        for (const string& months_sets : months_set){
            if (date.find(months_sets)!= string::npos){
                return true;
                }
        }
    }
    
    return false;
    }
}

void title_transfer(){
    cout << "Your Transfer Record" << "\n";
    cout << "--------------------" << "\n\n";
}

void from_to_account(){
    Transaction trans;
    cout << "Day Date (DD-MM-YY) : ";
    cin.ignore();
    getline(cin, trans.date);

    if (!check_month(trans.date)){
        cout << "Invalid month format. Use DD-MMM-YY (e.g., 28-May-2023)" << "\n";
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

void display(){
    if (transactions.size() == 0){
        cout << "No Transactions Found!" << endl;
    }
    cout << left << setw(20) << "Date" << setw(20) << "Name" << setw(30) << "Transfer Amount" << setw(30) << "From Account" << setw(20) << "To Account" << "\n";
    for(int i=0; i < transactions.size(); i++){
        cout << left <<setw(20) << transactions[i].date << setw(20) << transactions[i].name << setw(30) << transactions[i].transamount << setw(30) << transactions[i].fromAccount << setw(20) << transactions[i].toAccount << "\n";
        }
}

int main (){
    int g;
    do{
        displaymainmenu();
        cout << "Enter choice: ";
        cin >> g;

        switch (g){
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
    }
    while (g != 3);


    return 0;
}
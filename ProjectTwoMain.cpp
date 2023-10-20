#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include "InvestData.h"
#include "UserData.h"

using namespace std;

void mainScreen(){
    InvestData userInvest;
    UserData userData;

    double initialAmount;
    double monthlyDeposit;
    double interest;
    int years;
    string choice;
    bool cntRun = true;

    do{
		cout << setfill('*') << setw(34) << '*' << endl;
		cout << "*\t" << "Financial Data Input" << "\t *" << endl;
		cout << setfill('-') << setw(34) << '-' << endl;

		cout << "Initial Investment Amount: $";
		cin >> initialAmount;
		cout << endl;

		cout << "Monthly Deposit: $";
		cin >> monthlyDeposit;
		cout << endl;

		cout << "Annual Interest: %";
		cin >> interest;
		cout << endl;

		cout << "Number of years: ";
		cin >> years;
		cout << endl;

        userInvest.setInitialInvest(initialAmount);
        userInvest.setMonthDeposit(monthlyDeposit);
        userInvest.setAnnualInterest(interest);
        userInvest.setNumYears(years);

        cout << "Investment Amount: " << setfill(' ') << right << setw(10) << "$" << userInvest.getInitialInvest() << endl;
		cout << "Monthly Deposit Amount: " << setfill(' ') << right << setw(20) << "$" << userInvest.getMonthInvest() << endl;
		cout << "Annual Interest Amount: " << setfill(' ') << right << setw(20) << " " << userInvest.getAnnualInterest() << "%" << endl;
		cout << "Number of years: " << setfill(' ') << right << setw(20) << " " << userInvest.getNumYears() << endl;

        cout << endl;

        try {

            userData.dataWODeposits(userInvest);
        }
        catch(const std::exception& exc){
            cout << exc.what() << endl;
            cout << "An error has occured with our data" << endl;
            cntRun = false;
        }
        try{
            userData.dataWDeposits(userInvest);
        }
        catch(const std::exception& exc){
            cout << exc.what() << endl;
            cout << "An error has occured with our data" << endl;
            cntRun = false;
        }
        cout << endl;

        cout << "Would you like to continue? Yes or No?" << endl;
        cin >> choice;
        if (choice == "No"){
            cntRun = false;
        }
        else{
            continue;
        }
    }while(cntRun ==true);
    
}

int main(){
    try{
        mainScreen();
    }
    catch(const std::exception& exc){
            cout << exc.what() << endl;
            cout << "An error has occured with our data" << endl;
        }
}


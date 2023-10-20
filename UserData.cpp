#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

using namespace std;

#include "UserData.h"

void UserData::dataWODeposits(InvestData userInvestment){

    double initialInvestment = userInvestment.getInitialInvest();
    int years = userInvestment.getNumYears();

    int screenWidth = 100;
    string msg = "Data Without monthly deposits";
    int centerScreen = msg.length()/2;
    int halfWidth = screenWidth / 2;
    int sizeCenter = halfWidth + centerScreen;

    cout << setfill(' ') << setw(sizeCenter) << msg << setfill(' ') << setw(sizeCenter) << endl;
    cout << setfill('*') << setw(100) << '*' << endl;
    cout << setfill(' ') << left << setw(26) << "Year" << "Year Earned Interest" << right << setw(30) << "Year Balance" << endl;
    cout << setfill('*') << setw(80) << '*' << endl;

    userInvestment.setTotalWODeposits(initialInvestment);
    double interestYearToDate = 0;

    unsigned int yearCount, monthCount;

    for (yearCount = 1; yearCount <= years; yearCount++){
        for(monthCount = 1; monthCount <= 12; monthCount++){
            interestYearToDate += userInvestment.calcInterestWODeposits();
        }
        userInvestment.setTotalWODeposits(interestYearToDate);
        cout << setfill(' ') << left << setw(30) << yearCount;
        cout << "$" << fixed << setprecision(2) << interestYearToDate;
        cout << right << setw(35) << "$" << fixed << setprecision(2) << userInvestment.getTotalWODeposits() << endl;

        interestYearToDate = 0;
    }
}

void UserData::dataWDeposits(InvestData userInvestment){

    double initialInvestment = userInvestment.getInitialInvest();
    double monthlyDeposit = userInvestment.getMonthInvest();
    int years = userInvestment.getNumYears();

    string msg = "Data with monthly deposits";
    int screenWidth = 100;
    int centerScreen = msg.length()/2;
    int halfWidth = screenWidth / 2;
    int sizeCenter = halfWidth + centerScreen;

    cout << setfill(' ') << setw(sizeCenter) << msg << setfill(' ') << setw(sizeCenter) << endl;
    cout << setfill('*') << setw(100) << '*' << endl;
    cout << setfill(' ') << left << setw(26) << "Year" << "Year Earned Interest" << right << setw(30) << "Year Balance" << endl;
    cout << setfill('*') << setw(80) << '*' << endl;

    userInvestment.setTotalWDeposits(initialInvestment);

    double interestYearToDate = 0;

    unsigned int yearCount, monthCount;

    for (yearCount = 1; yearCount <= years; yearCount++){
        for (monthCount = 1; monthCount <= 12; monthCount++){
            userInvestment.setTotalWDeposits(monthlyDeposit);
            double interest = userInvestment.calcInterestWDeposits();
            userInvestment.setTotalWDeposits(interest);
            interestYearToDate += interest;
        }

        cout << setfill(' ') << left << setw(26) << yearCount;
        cout << "$" << fixed << setprecision(2) << interestYearToDate;
        cout << right << setw(35) << "$" << fixed << setprecision(2) << userInvestment.getTotalWDeposits() << endl;

        interestYearToDate = 0;
    }
}
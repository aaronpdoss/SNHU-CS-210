#include <iostream>
using namespace std;

#include "InvestData.h"

void InvestData::setInitialInvest(double initialInvestment){

    this -> initialInvestment = initialInvestment;

}

void InvestData::setMonthDeposit(double monthDeposit){

    this -> monthDeposit = monthDeposit;

}

void InvestData::setAnnualInterest(double annualInterest){

    this -> annualInterest = annualInterest;

}

void InvestData::setNumYears(double years){

    this -> years = years;
}

void InvestData::setTotalWODeposits(double amount){

    this -> totalWODeposits += amount;
}

void InvestData::setTotalWDeposits(double amount){

    this -> totalWDeposits += amount;
}

double InvestData::calcInterestWODeposits(){

    return ((this -> totalWODeposits) * ((this -> annualInterest/100)/12));

}

double InvestData::calcInterestWDeposits(){

    return((this -> totalWDeposits)*((this -> annualInterest/100)/12));

}

double InvestData::getTotalWDeposits(){
    
    return this -> totalWDeposits;

}

double InvestData::getTotalWODeposits(){

    return this -> totalWODeposits;
}
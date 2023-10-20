#pragma once
#ifndef AIRGEADBANKING_INVESTMENTDATA_H_
#define AIRGEADBANKING_INVESTMENTDATA_H_
#endif

class InvestData{
    private:
        double initialInvestment = 0.0;
        double monthDeposit = 0.0;
        double annualInterest = 0.0;
        int years = 0;
        double totalWDeposits = 0.0;
        double totalWODeposits = 0.0;

    public:
        //setter methods
        void setInitialInvest(double initialInvestment);
        void setMonthDeposit(double monthDeposit);
        void setAnnualInterest(double annualInterest);
        void setNumYears(double years);
        void setTotalWDeposits(double amount);
        void setTotalWODeposits(double amount);

        //getter methods
        double getInitialInvest(){

            return initialInvestment;

        }

        double getMonthInvest(){

            return monthDeposit;

        }

        double getAnnualInterest(){

            return annualInterest;

        }

        int getNumYears(){

            return years;

        }

        double getTotalWDeposits();
        double getTotalWODeposits();

        double calcInterestWDeposits();
        double calcInterestWODeposits();



};
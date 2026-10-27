//
// Created by thedi on 10/22/2026.
//

#ifndef BANKAPPV1_1_CHECKINGACCOUNT_H
#define BANKAPPV1_1_CHECKINGACCOUNT_H
#include "BankAccount.h"

class CheckingAccount:public BankAccount
{
private:
    double m_overDraftLimit;
public:
    CheckingAccount(const std::string &accHolder, const std::string &accNum, double balance, double overDraftLimit);
    ~CheckingAccount();
    bool withdraw(double amount);
    void display();




};


#endif //BANKAPPV1_1_CHECKINGACCOUNT_H

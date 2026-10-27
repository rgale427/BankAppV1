//
// Created by thedi on 10/22/2026.
//

#include "CheckingAccount.h"

#include <iostream>
#include <ostream>

CheckingAccount::CheckingAccount(const std::string &accHolder, const std::string &accNum, double balance, double overDraftLimit):BankAccount(accHolder, accNum, balance)
{
    m_overDraftLimit = overDraftLimit;
}
CheckingAccount::~CheckingAccount()
{
    std::cout<< "\nCheckingAccount Object Deconstructed\n";
}
bool CheckingAccount::withdraw(double amount) //override base class withdraw method - form of polymorphism
{
    if (amount <= m_balance + m_overDraftLimit)
    {
        if (amount > m_balance)
        {
            m_overDraftLimit += (m_balance - amount);
           }
            m_balance -= amount;

            return true;
    }
    if (m_balance < 0 and amount <= m_overDraftLimit)
    {
        m_overDraftLimit -= amount;
        m_balance -= amount;
    return true;
    }
    else
    {
        return false;
    }
}
void CheckingAccount::display()
{
    BankAccount::display();
    std::cout << "Overdraft Limit: $" << m_overDraftLimit << std::endl;
}
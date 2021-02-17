#include "bankaccount.h"

BankAccount::BankAccount(Bank *parentBank) : QObject(parentBank)
{
    m_balance = 0;

    QObject::connect(
                this, &BankAccount::balanceChanged,
                parentBank, &Bank::accountChanged
                );
    // TODO: connect Bank slots to BankAccount signals
}

long BankAccount::balance() const
{
    return m_balance;
}

void BankAccount::setBalance(long newBalance)
{
    m_balance = newBalance;
    // here is signal emition
    emit balanceChanged(newBalance);
}

void BankAccount::deposit(long amount)
{
    m_balance += amount;
    if (amount!=0)
    {
        emit balanceChanged(m_balance);
    }
}

void BankAccount::withdraw(long amount)
{
    m_balance -= amount;
    if (amount!=0)
    {
        emit balanceChanged(m_balance);
    }
}

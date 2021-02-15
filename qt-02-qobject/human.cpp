#include "human.h"
#include<QDebug>

Human::Human(QString firstName, QString secondName, Sex sex, QDate birthDate, QObject *parent)
    : QObject(parent)
    , m_firstName(firstName)
    , m_secondName(secondName)
    , m_sex(sex)
    , m_birthDate(birthDate)
{
    setObjectName(firstName+secondName);
}

QString Human::firstName() const
{
    return m_firstName;
}

QString Human::secondName() const
{
    return m_secondName;
}

Human::Sex Human::sex() const
{
    return m_sex;
}

QDate Human::birthDate() const
{
    return m_birthDate;
}

void Human::print() const
{
    qDebug()<<QString(m_firstName[0])+". "+m_secondName<<"\n"
            <<(m_sex == Sex::male?"(M)":"(F)")<<"\n"
            <<"Age: "<< QDate::currentDate().year()-m_birthDate.year()<<"\n";

}

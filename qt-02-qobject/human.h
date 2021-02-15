#ifndef HUMAN_H
#define HUMAN_H

#include <QObject>
#include <QDate>
class Human : public QObject
{
    Q_OBJECT
public:
    enum class Sex
    {
        male,
        female
    };

    explicit Human(QString firstName, QString secondName, Sex sex, QDate birthDate, QObject *parent = nullptr);


    QString firstName() const;

    QString secondName() const;

    Sex sex() const;

    QDate birthDate() const;

    void print() const;

signals:
private:


    QString m_firstName;
    QString m_secondName;
    Sex m_sex;
    QDate m_birthDate;
};

#endif // HUMAN_H

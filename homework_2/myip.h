#ifndef MYIP_H
#define MYIP_H

#include<QList>
class MyIp
{
public:
    MyIp(QList<quint8> listIp);
    MyIp(const QString &stringIp);
    QString toString() const;
private:
    QList<quint8> m_ip;
};

inline bool operator ==(const MyIp& left, const MyIp& right)
{
    return left.toString() == right.toString();
}

inline uint qHash(const MyIp& key)
{
    return qHash(key.toString());
}

#endif // MYIP_H

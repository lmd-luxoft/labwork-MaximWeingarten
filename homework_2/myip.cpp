#include "myip.h"
#include <stdexcept>
MyIp::MyIp(QList<quint8> listIp)
{
    if (listIp.size()!=4)
    {
        throw std::invalid_argument("invalid ip address");
    }
    m_ip = listIp;
}

MyIp::MyIp(const QString &stringIp)
{
    QList ip = stringIp.split(".");
    if (ip.size()!=4)
    {
        throw std::invalid_argument("invalid ip address");
    }
    for (auto& s: ip)
    {
        bool ok;
        m_ip<<s.toShort(&ok);
        if (!ok)
        {
            throw std::invalid_argument("invalid ip address");
        }
    }
}

QString MyIp::toString() const
{
    QStringList result;
    for (auto &e:m_ip)
    {
        result << QString::number(e);
    }
    return result.join(".");
}

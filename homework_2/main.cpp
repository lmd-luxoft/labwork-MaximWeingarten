#include<myip.h>
#include<QDebug>
int main()
{
    MyIp ip1(QList<quint8>{127,0,0,1});
    MyIp ip2("192.168.192.168");
    QHash<MyIp, QString> hash;
    hash[ip1] = "localhost";
    hash[ip2] = "target.net";
    for(auto it = hash.begin(); it!= hash.end(); it++)
    {

        qDebug()<<it.key().toString()
               << it.value();
    }
    return 0;
}

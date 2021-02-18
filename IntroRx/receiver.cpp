#include "receiver.h"
#include <QDebug>
Receiver::Receiver(QObject *parent) : QObject(parent)
{

}

void Receiver::OnNextHandler(int value)
{
    qDebug()<<value;
}

void Receiver::OnCompletedHandler()
{
    qDebug()<<"Data collection completed";
}

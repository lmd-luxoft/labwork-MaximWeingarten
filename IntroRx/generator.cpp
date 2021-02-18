#include "generator.h"
Generator::Generator(int start, int stop, int step, QObject* parrent)
    : QObject(parrent)
    , currentValue(start)
    , stepValue(step)
    , stopValue(stop)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout,
            this, &Generator::timerHandler);
}

void Generator::run(int interval)
{
    timer->start(interval);
}

void Generator::timerHandler()
{
    emit OnNext(currentValue);
    if (currentValue>=stopValue)
    {
        emit OnCompleted();
    }
    else
    {
        currentValue += stepValue;
    }
}

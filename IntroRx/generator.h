#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>
#include <QTimer>
class Generator: public QObject
{
    Q_OBJECT
public:
    Generator(int start, int stop, int step, QObject* parrent = nullptr);
    void run(int interval);
signals:
    void OnNext(int value);
    void OnError(int errorCode);
    void OnCompleted();

private:
    int currentValue;
    int stepValue;
    int stopValue;
    QTimer *timer;
private slots:
    void timerHandler();
};

#endif // GENERATOR_H

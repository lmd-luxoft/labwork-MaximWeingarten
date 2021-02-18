#include <generator.h>
#include <QCoreApplication>
#include <receiver.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Generator g(1, 200, 2);
    Receiver r1, r2;
    QObject::connect(
                &g, &Generator::OnNext,
                &r1, &Receiver::OnNextHandler
                );
    QObject::connect(
                &g, &Generator::OnCompleted,
                &r1, &Receiver::OnCompletedHandler
                );
    QObject::connect(
                &g, &Generator::OnNext,
                &r2, &Receiver::OnNextHandler
                );

    QObject::connect(
                &g, &Generator::OnCompleted,
                &a, &QCoreApplication::quit
                );
    g.run(100);
    return a.exec();
}

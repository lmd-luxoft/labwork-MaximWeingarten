#include <QCoreApplication>
#include <QDebug>
#include <human.h>
void printTreeInfo(QObject *parent)
{
    // print here info about all nodes
    Human *h = qobject_cast<Human*>(parent);
    h->print();
    for (auto c: parent->children())
    {
        printTreeInfo(c);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // create here required hierarchy

    Human* parent = new Human("Dorian", "Gray", Human::Sex::male, QDate(1967, 1, 1));
    Human* child1 = new Human("Jason", "Gray", Human::Sex::male, QDate(1989, 1, 1), parent);
    Human* child2 = new Human("Mary", "Gray", Human::Sex::female, QDate(1993, 1, 1), parent);
    Human* granchild1 = new Human("Jessica", "Gray", Human::Sex::female, QDate(2020, 1, 1), child1);
    Human* granchild2 = new Human("Hunnah", "Gray", Human::Sex::female, QDate(2020, 1, 1), child1);
    Human* granchild3 = new Human("Sean", "Gray", Human::Sex::male, QDate(2016, 1, 1), child1);
    Human* granchild4 = new Human("Fred", "Smith", Human::Sex::male, QDate(2019, 1, 1),child2);
    Human* granchild5 = new Human("Jane", "Smith", Human::Sex::female, QDate(2019, 1, 1),child2);

    // dump tree info using standard Qt method
    parent->dumpObjectTree();


	
    printTreeInfo(parent);
    // delete here what need only
    delete parent;


    return a.exec();
}

#include <QCoreApplication>
#include <QDebug>
#include <QStack>

int main(int argc, char *argv[])
{
    QList<QString> names;
    names << "Mary" << "Ann" << "Charlynn" << "Marylynn" << "Margaret"
          << "Kate" << "Rose" << "Gwendolyn";

    // TODO: using Java-style iterators print the longest name from the list
    QListIterator<QString> i(names);
    QString longest = "";
    while (i.hasNext())
    {
        auto nxt = i.next();
        if (nxt.size()>longest.size())
        {
            longest = nxt;
        }
    }

    // use QString::arg to output message with this name
    QString message = "The longest name is %1.";
    qDebug()<<message.arg(longest);

    // TODO: using STL-style iterators print the shortest name from the list
    QString shortest = names.at(0);
    for (auto it = names.begin()+1;it!=names.end();it++)
    {
        if (it->size()<shortest.size())
        {
            shortest = *it;
        }
    }
    // use QString::prepend and append to output message with this name
    shortest.prepend("The shortest string is ");
    shortest.append(".");
    qDebug()<<shortest;
    // TODO: using foreach and QStringList show all names with "lynn" suffix
    QString separator = "";
    QList<QString> lynnList;
    for (auto &s: names)
    {
        if (s.endsWith("lynn"))
        {
            lynnList << s;
        }
    }
    qDebug()<<lynnList.join(", ");
    // and print it separated by ',' as one string


    // print all names in reverse order
    // TODO: 1. Using QStack
    qDebug()<<"reverse with stack";
    QStack<QString> stack;
    for (auto &s: names)
    {
        stack.push(s);
    }
    while (!stack.empty())
    {
        qDebug()<<stack.pop();
    }
    // TODO: 2. Using other QList
    qDebug()<<"reverse with list";
    QList rnames(names.rbegin(), names.rend());
    qDebug()<<rnames.join(", ");
    // TODO: 3. Without other containers
    qDebug()<<"reverse with riterator";
    for(auto it = names.rbegin(); it!= names.rend(); it++)
    {
        qDebug()<<*it;
    }
}

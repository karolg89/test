#include <QCoreApplication>
#include <QList>
#include <QDebug>

class MyClass
{
    public:
        int x;

    public:
        MyClass(int x)
        {
            this->x = x;
        }

        bool  operator==(const MyClass  &c2)
        {
            if(this->x==c2.x)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<MyClass> list;

    list.append(MyClass(5));
    list.append(MyClass(5));
    list.append(MyClass(5));
    list.append(MyClass(5));

    for(int i = 0; i < 10; i ++)
    {
         list.append(MyClass(i));
    }

    list.removeAll(MyClass(5));

    foreach (MyClass l, list) {
        qDebug() << l.x;
    }

    return a.exec();
}

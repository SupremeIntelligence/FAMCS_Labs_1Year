#include <QCoreApplication>
#include<QDebug>
#include<QMap>
#include<QMultiMap>
#include<iostream>
#include<Windows.h>

using namespace std;

void Menu (QMap<QString, double>& map, QMultiMap<QString, double>& qmultimap)
{
    cout << "------------------------------------------\n";
    cout << "1.Вывод map на консоль\n";
    cout << "2.Удалить элементы из заданного диапазона\n";
    cout << "3.Поиск первого элемента меньшего заданного ключа\n";
    cout << "4. Скопировать элементы в новый multimap\n";
    cout << "5.Замена значения элемента\n";
    cout << "6.Добавить элемент\n";
    cout << "7.Выход из программы\n";
    cout << "------------------------------------------\n";

    QTextStream cout(stdout);
    QTextStream cin(stdin);

    QMap<QString, double> :: iterator it = map.begin();
    QMultiMap<QString, double> ::iterator multi_it = qmultimap.begin();
    QMap<QString, double> :: iterator temp_it;
    //using qpair = pair<QString, double>;
    int button;
    QString name;
    double value;

    cin >> button;
    do
    {
        switch (button)
        {
        case 1:
            qDebug() << "Output QMap:";
            it=map.begin();
            while (it!=map.end())
            {
                qDebug() << "["<<it.key()<<", " << it.value() << "]";
                it++;
            }

            cin>>button;
            break;

        case 2:
            qDebug()<< "Enter the range of the elements from:";
            cin>>value; //first
            it = map.begin();

            for (int i = 0; i < value; i++)
            {
                it++;
            }

            qDebug()<< "to:";
            cin>>value; //last
            temp_it = map.begin();
            for (int i = 0; i < value; i++)
            {
                temp_it++;
            }
            qDebug()<< "Erasing the map";
            map.erase (it-1, temp_it);



            cin>>button;
            break;

        case 3:

            qDebug () <<"Enter the key (name):";
            cin>>name;


            temp_it = map.begin();
            if (map.contains (name))
            {
                temp_it = map.find(name);
            }
            else
            {
                qDebug() << "The entered key does not exist";
                cin>>button;
                break;
            }

            it = temp_it;
            while (it!=map.end())
            {
                if ( it.value() < temp_it.value())
                {
                    temp_it = it;
                    break; //or it = map.end();
                }
                it++;
            }
            qDebug () << "The element is found: ["<<temp_it.key()<<", "<<temp_it.value()<<"]";
            cin>>button;
            break;

        case 4:
            qDebug()<<"\nCopying items to a new multimap";
            qmultimap.clear();
            it = map.begin();

            while (it!=map.end())
            {
                qmultimap.insert(it.key(), it.value());
                it++;
            }

            qDebug()<<"Output MultiMap:";
            multi_it = qmultimap.begin();

            while(multi_it!=qmultimap.end())
            {
                qDebug()<< "[" <<multi_it.key()<<", "<<multi_it.value()<<"]";
                multi_it++;
            }

            cin>>button;
            break;

        case 5:
            qDebug() << "\nEnter the key of element (name) whose value (age) you want to change:\t";
            cin>>name;

            if (map.contains(name))
            {
                qDebug()<<"\nEnter the new value (age):\t";
                cin>>value;
                map[name]=value;
            }
            else
            {
                qDebug()<<"\nThe element does not exist;\n";
            }
            cin>>button;
            break;

        case 6:
            qDebug()<< "Enter the name (key):\t";
            cin>>name;
            qDebug()<< "Enter the age (value): \t";
            cin >> value;
            map.insert(name, value);

            cin>>button;
            break;

        case 7:

            cin>>button;
            break;

        default:
            cin>>button;
            break;
        }
    }
    while (button != 7);
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream cout(stdout);
    QTextStream cin(stdin);

    setlocale (LC_ALL, " ");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    using qpair = pair<QString, double>;

    QMap<QString, double> qmap =
        {
            qpair("Kirill", 18),
            qpair("Vladislav", 23),
            qpair("Vlada", 35),
            qpair("Oleg", 10),
            qpair("Sasha", 34),
        };

    QMultiMap<QString, double> qmultimap;

    Menu(qmap, qmultimap);
    return 0;//a.exec();
}

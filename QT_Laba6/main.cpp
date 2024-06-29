#include <QCoreApplication>
#include <QTextStream>
#include<QDebug>
#include<iostream>
#include<QList>
#include<list>
#include<Windows.h>
using namespace std;

list<quint16> QTtoSTD(const QList<quint16>& qlist)
{
    list<quint16> clist (qlist.size());
    copy_backward(qlist.begin(),qlist.end(), clist.end());
    return clist;
}

QList<quint16> STDtoQT(const list<quint16>& clist)
{
    QList<quint16> qlist (clist.size());
    copy_backward(clist.begin(), clist.end(), qlist.end());
    return qlist;
}


void Menu(QList<quint16>& list)
{
    cout << "---------------------------------------------------------- \n";
    cout << "1.View the status of the list\n" << "2.Add an element to the specified position\n" << "3.Delete an item at the specified position\n";
    cout << "4.Resize the list\n" << "5.Increase all elements by X, use the transform algorithm.\n";
    cout << "6.Delete items by condition(remove_if)\n" << "7.Exit the program\n";
    cout << "---------------------------------------------------------- \n\n";

    QList<quint16> :: iterator it = list.begin();
    //QListIterator<quint16> it (list);
    //ostream_iterator<quint16> itr_out(cout, "\n");

    int button;
    size_t pos;
    quint16 value;
    qsizetype size;

    cin>>button;

    do
    {
        switch (button)
        {
        case 1:
            cout<< "List content:\n";
            while (it != list.end())
            {
               cout<<*it<<" ";
                ++it;
            }
            cout<<endl;
            it = list.begin();
            cin >> button;
            break;

        case 2:
            cout<<"Enter the value and it's position: \t";
            cin>>value>>pos;
            while (pos > list.size()+1 || pos <= 0 )
            {
                cout << "\nThe position must be greater than zero. Try again.\n";
                cin >> pos;
            }
            if (pos == list.size()+1)
            {
                list.append (value);
            }
            else
            {
                list.append (value);
                pos-=1;
                list.move (list.size()-1, pos);
            }
            cin >> button;
            break;

        case 3:
            cout<<"Enter the position of element you want to remove: \t";
            cin>>pos;
            while (pos > list.size() || pos <= 0)
            {
                cout << "\nThe position must be greater than zero. Try again.\n";
                cin >> pos;
            }
            pos-=1;
            list.removeAt(pos);

            cin >> button;
            break;

        case 4:
            cout << "Enter the new size of the list: \t";
            cin >> size;
            while (size <= 0)
            {
                cout << "\nThe size must be greater than zero. Try again. \n";
                cin >> size;
            }
            list.resize(size, 0);

            cin >> button;
            break;

        case 5:
            cout<<"Enter the value you want to increase your list by: \t";
            cin>> value;
            while (it != list.end())
            {
                *it += value;
                it++;
            }
            it = list.begin();
            cin >> button;
            break;

        case 6:
            cout<<"Enter the value: \t";
            cin>>value;
            while (value < 0)
            {
                cout<< "\nThe value must be greater than zero or equal. Try again";
                cin>>value;
            }
            cout<<"\n/////Deleting elements/////\n";
            while (it!= list.end())
            {                                                           //можно сделать через erase_if, но он есть в версии, начиная с qt 6.1

                if (15 - qCountLeadingZeroBits(*it) > value)            //функция qCountLeadingZeroBits подсчитывает число ведущих нулевых битов, которые идут слева от первой значащей единицы.
                {                                                       //данный код удаляет из списка элементы, которые больше либо равны, чем число 2^(value+1)  (т.е элементы, у которых число ведущих нулей больше, чем 15-value)
                    list.removeAt(list.indexOf(*it));

                }
                else
                {
                    it++;
                }

            }
            it = list.begin();

            cin >> button;
            break;

        default:
            cout << "Non-direct input. Try again.\n";
            cin >> button;
            break;
        }


    }while (button!=7);
    cout<<".....Exiting the program.....";


}

int main(int argc, char* argv [])
{
    QTextStream cout(stdout);
    QTextStream cin(stdin);
    QCoreApplication a(argc, argv);

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    QList<quint16> qlist;
    qlist << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9;

    list<quint16> clist = QTtoSTD(qlist);
    qlist.clear();

    qlist = STDtoQT(clist);

    Menu(qlist);

    return a.exec();
}

// EvdokimovAV.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include<string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    //Задача 1. Вычислить факториал натурального числа.
    /*
    int f,x,n = 1;
    cout << "Введите натуральное число, факториал которого хотите вычислит" << endl;
    cin >> f;
    x = f;
    while (n != f) {
        x = n * x;
        n++;
    }
    cout << "Факториал равен=" << x << endl; */

    //Задача 2. Найти НОД и НОК двух заданных натуральных чисел.
    /* int x, y, nok, nod;
    cout << "Введите X и Y:" << endl;
    cin >> x >> y;
    nok = x * y;
    while (x != y)
    {
        if (x < y)
            y -= x;
        if (y < x)
            x -= y;
    }
    nod = x;
    nok /= nod;
    cout << "НОД (x,y) =" << nod << endl;
    cout << "НОК (x,y) =" << nok << endl;
    */

    //Задача 3. Найти сумму цифр целого числа (проверять и отрицательные числа).
    /*int x, y;
    y = 0;
    cout << "Введите число:" << endl;
    cin >> x;
    while (x)
    {

        y = y + x % 10;
        x = x / 10;
    }

    cout <<"Сумма цифр числа X = "<< y;
    */

    //Задача 4. Решить квадратное уравнение (реализовать для всех вариантов с нулевыми коэффициентами).
    /*int x1, x2, a, b, c, D, i;

    cout << "Введите коэффиценты а, b и c:" << endl;
    cin >> a >> b >> c;
    if (a != 0)
    {

        D = (pow(b, 2)) - (4 * a * c);
        if (D > 0) {
            i = 1;
        }
        else {
            if (D == 0) {
                i = 0;
            }
            else {
                i = 2;
            }
        }


        switch (i)
        {
        case 1:
        {
            x1 = (-b - sqrt(D)) / (2 * a);
            x2 = (-b + sqrt(D)) / (2 * a);
            cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
            break;
        }
        case 2:
        {
            cout << "Нет действительных корней" << endl;
            break;
        }
        case 0:
        {
            int x = (-b) / 2 * a;
            cout << "Корень уравнения = " << x << endl;
            break;
        }

        }
    }
    else
        cout << "Уравнение не является квадратным";*/

        /*Задача 5.Разработать программу для вывода на экран компьютера N строк трапеции(размер L верхней стороны трапеции и N
            ввести с консоли) состоящего из символов '*' и имеющего вид(для L = 2, N = 3) :
                **
                ***
                **** */
                /*int L, N;
                        char star =* "*";
                        cout << "Введите L и N:" << endl;
                        cin >> L >> N;
                        for (int i = 1;i <= N;i++)
                        {
                            cout << string(L, star) << endl;
                            L++;
                        }
                        */

                        //Задача 6. Является ли число палиндромом (проверять и отрицательные числа).
                       /*
                           int p, n, proverka;
                           n = 0;
                           cout << "Введите число:" << endl;
                           cin >> p;
                           proverka = p;
                           while (p)
                           {
                               n = n * 10 + p % 10;
                               p = p / 10;
                           }
                           if (proverka == n)
                           {
                               cout << proverka << " является палиндромом" << endl;
                           }
                           else
                           {
                               cout << proverka << " не является палиндромом" << endl;
                           }
                           */

                           /*Задача 7. Вычислить X в степени N.n – любое, не обязательно целое.Тип переменных double.Проверить корректность ввода :
                           x = 0, n = 0; x = 0, n < 0;x < 0, n - не целое.*/
/*double x, n, power;
power = 0;
cout << "Введите число X и его степень N:" << endl;
cin >> x >> n;
power = pow(x, n);
cout << "X в степени N = " << power << endl;
*/

                           //Задача 8. Является ли натуральное число простым.
                          
                      int x, n=0;
                          cout << "Введите натуральное число:" << endl;
                          cin >> x;

                          for (int i = 1;i < x;i++)
                          {
                              if (x % i == 0)
                              {
                                  n++;
                             }
                         }
                          if (x > 1)
                          {
                              if (n<2)
                              {
                                  cout << x << " простое число"<<endl;
                              }
                              else
                              {
                                  cout << x << " составное число" << endl;
                              }
                          }
                          else
                          {
                              if (x == 1)
                              {
                                  cout << "1 не является ни простым, ни составным числом" << endl;
                              }
                              else
                              {
                                  cout << "Простые числа должны быть положительными" << endl;
                              }
                          }
                          
    //Задача 10. Вывести количество разных цифр. 
   /* int a;
    cin >> a;
    int x = 0, x0 = 0, x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0, x7 = 0, x8 = 0, x9 = 0;
    while (a > 0)
    {
        int buf = a % 10;
        if (buf == 0) x0++;
        else if (buf == 1) x1++;
        else if (buf == 2) x2++;
        else if (buf == 3) x3++;
        else if (buf == 4) x4++;
        else if (buf == 5) x5++;
        else if (buf == 6) x6++;
        else if (buf == 7) x7++;
        else if (buf == 8) x8++;
        else if (buf == 9) x9++;
        else if (buf == 0) x0++;
        a /= 10;
    }
    if (x1 > 0) x++;
    if (x2 > 0) x++;
    if (x3 > 0) x++;
    if (x4 > 0) x++;
    if (x5 > 0) x++;
    if (x6 > 0) x++;
    if (x7 > 0) x++;
    if (x8 > 0) x++;
    if (x9 > 0) x++;
    if (x0 > 0) x++;
    cout << x;
    return 0;
    */
//Задача 11.  Вывести следующую дату после введенной(число, месяц, год)
/*
int day, month, year;
cout << "Введите число, месяц, год" << endl;
cin >> day >> month >> year;
if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
{
    if (day == 31)
    {
        day = 1;
        if (month == 12) 
        {
            year++;
            month = 1;
        }
    }
    else
    {
        day++;
    }
}
else
{
    if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (month == 2)
        {
            if (year % 4 == 0)
            {
                if (day == 29)
                {
                    day = 1;
                    month++;
                }
                else
                {
                    day++;
                }
            }
            else 
            {
                if (day == 28)
                {
                    day = 1;
                    month++;
                }
            }
        }
        else
        {
            if (day == 30)
            {
                day = 1;
                month++;
           }
            else
            {
                day++;
            }
        }
    }
}
if (month == 2 && day != 29 && day != 28)
{
    day++;
}
cout << "Следующая дата - " << day << "." << month << "." << year;
*/
}
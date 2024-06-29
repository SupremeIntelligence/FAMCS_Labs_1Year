// Evdokimov Laba 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<iomanip>
#include<time.h>
#include<cmath>
#include<string>
#include <sstream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
char operation, op;
void HoarSort(float mas[], int b, int e, int znak)
{
    float temp, c;
    int  i, j;
    c = mas[(b + e) / 2]; //находим центральный элемент массива

    i = b;
    j = e; // инициализируем индексы начала и конца массива
    if (znak == 1)
    {
        while (i <= j)
        {
            while (mas[i] < c)
            {
                i++; //если элемент слева меньше c, то переходим к i+1
            }
            while (mas[j] > c)
            {
                j--; //если элемент справа больше c, то переходим к j-1
            }
            if (i <= j) //если левый член меньше правого, то меняем их местами и переходим к соседним индексам
            {
                temp = mas[i];
                mas[i] = mas[j];
                mas[j] = temp;
                i++;
                j--;

            }
            if (b < j)
            {
                HoarSort(mas, b, j, znak);

            }
            if (i < e)
            {
                HoarSort(mas, i, e, znak);
            }
        }




    }
    else
    {
        while (i <= j)
        {
            while (mas[i] > c)
            {
                i++; //если элемент слева меньше c, то переходим к i+1
            }
            while (mas[j] < c)
            {
                j--; //если элемент справа больше c, то переходим к j-1
            }
            if (i <= j) //если левый член меньше правого, то меняем их местами и переходим к соседним индексам
            {
                temp = mas[i];
                mas[i] = mas[j];
                mas[j] = temp;
                i++;
                j--;

            }
            if (b < j)
            {
                HoarSort(mas, b, j, znak);

            }
            if (i < e)
            {
                HoarSort(mas, i, e, znak);
            }
        }
    }
}

int CountingDigits(float x)
{
    int counter = 0;
    stringstream ss;
    ss << setprecision(6) << x;
    string strNum = ss.str();
    size_t pos = strNum.find('.');
    if (pos != strNum.npos)
    {
        counter = strNum.size() - 1 - pos;
    }
    return counter;
}
    
void CountSort(float mas[], int numb, int znak)
{
    float max_value = 0;
    float min_value = 0;
    int counterMax = 0; //максимальное количество знаков после запятой в элементах массива
    int temp_counter = 0;
    //ищем counterMax
    for (int i = 0; i < numb; i++)
    {
        temp_counter = CountingDigits(mas[i]);
        if (temp_counter > counterMax) counterMax = temp_counter;
    }

    //домножаем элементы массива на 10^counterMax
    for (int i = 0; i < numb; i++)
    {
        mas[i] = mas[i] * powf(10, counterMax);
        max_value = max(max_value, mas[i]); //находим максимальный элемент в массиве
        min_value = min(min_value, mas[i]); //находим минимальный элемент в массиве
    }
    int imin_value = static_cast<int>(min_value);
    int imax_value = static_cast<int>(max_value);

    int range = imax_value - imin_value + 1; //количество чисел между минимальным и максимальным значениями массива включительно
    int* count = new int[range];
    for (int i = 0; i < range; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < numb; i++)
    {
        int temp = static_cast<int>(mas[i]);
        count[temp - imin_value]++;
    }
    
    if (znak == 1)
    {
        int idx = 0;
        for (int i = 0; i < range; i++)
        {
            while (count[i] > 0)
            {
                mas[idx] = static_cast<float>(i + imin_value) / powf(10, counterMax);
                idx++;
                count[i]--;
            }
        }
    }
    else 
    {
        int idx = numb - 1;
        for (int i = 0; i < range; i++)
        {
            while (count[i] > 0)
            {
                mas[idx] = static_cast<float>(i + imin_value) / powf(10, counterMax);
                idx--;
                count[i]--;
            }
        }
    }
    delete[] count;
}

int choose_op()
{
    setlocale(LC_ALL, "RUS");
    cout << "Отсортировать массив по возрастанию или по убыванию? (+/-)" << endl;
    cin >> operation;
    if (operation == '+')
    {
        op = 1;
        return op;
    }
    else if (operation == '-')
    {
        op = 0;
        return op;
    }
    else 
        return 0;
}

void ArrayOutput(float mas[], int numb, int znak)
{

    if (znak == 1)
    {
        cout << "Массив, отсортированный по возрастанию:" << endl;

    }
    else
    {
        cout << "Массив, отсортированный по убыванию:" << endl;
    }
    for (int i = 0; i < numb; i++)
    {
        cout << mas[i] << "\t";
    }
}

int compareAscending(const void* a, const void* b) 
{
    float float_a = *((float*)a);
    float float_b = *((float*)b);

    if (fabs(float_a - float_b) < 1e-6)
    {
        return 0; 
    }
    else if (float_a < float_b)
    {
        return -1;
    }
    else if (float_a > float_b)
    {
        return 1;
    }
}

int compareDescending(const void* a, const void* b) {
    return compareAscending(b, a);
}

int main()
{
	setlocale(LC_ALL, "RUS");

	int numb;
    choose_op ();
	cout << "Введите размерность массива: ";
	cin >> numb;
	float *mas = new float[numb];
    int b = 0; //номер первого элемента массива
    int e = numb - 1; //номер конечного элемента массива
	srand(time(NULL));
	for (int i = 0; i < numb; i++)
	{
		mas[i] = rand()/100.000;
        cout << mas[i] << "\t";
	}
    cout << endl<<endl << "\tСортировка Хоара:" << endl;
    //сортировка Хоара
    /*if (op == 1)
    {
        HoarSort(mas, b, e);
    }
    else
    {
    */
    HoarSort(mas, b, e, op);
    ArrayOutput(mas, numb, op);

    //сортировка подсчетом
    cout << endl<<endl<< "\tСортировка подсчетом:"<<endl;
    CountSort(mas, numb, op);
    ArrayOutput(mas, numb, op);
	

    //qsort
    qsort (mas, numb-1, sizeof(float), (op==1) ? compareAscending : compareDescending);
    cout << endl << endl << "\tСортировка через qsort:" << endl;
    ArrayOutput(mas, numb, op);

    //sort
    cout << endl << endl << "\tСортировка через sort" << endl;
    sort(mas, mas + numb);
    ArrayOutput(mas, numb, 1);
    
   //bsearch
    float key;
    cout << endl << endl << "Введите элемент, который хотите найти: ";
    cin >> key;

    float* result = (float*) bsearch(&key, mas, numb - 1 , sizeof(float), (op == 1) ? compareAscending : compareDescending);

    if (result) 
    {
        cout << "Элемент " << key << " найден в массиве по адресу " << result << endl;
    }
    else 
    {
        cout << "Элемент " << key << " не найден в массиве." << endl;
    }



    delete[] mas;
    return 0;
}


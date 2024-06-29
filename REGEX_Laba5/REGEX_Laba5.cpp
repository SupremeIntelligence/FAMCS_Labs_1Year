#include <iostream>
#include<regex>
#include<string>
#include<fstream>
using namespace std;

bool isValidMACAddress(const string& str)
{
    regex rgx("(([0-9]|[A-F]|[a-f]){2}([\\-]|[:]){1}){5}(([0-9]|[A-F]|[a-f]){2})$");
    if (regex_match(str, rgx)) return true;
    else return false;
}
size_t AmountOfLines(istream& file)
{
    size_t counter = 0;
    string line;
    while (getline(file, line))
    {
        counter++;
    }
    file.clear();
    file.seekg(0, ios::beg);
    return counter;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    ifstream in("MAC-Address.txt");
    ofstream out("Output.txt");

    size_t size = AmountOfLines(in);
    string* MAC = new string[size];

    for (int i = 0; i < size; i++)
    {
        getline(in, MAC[i]);
        cout << MAC[i] << "\t";
        out << MAC[i] << "\t";
        if (isValidMACAddress(MAC[i]))
        {
            cout << "Адрес верный\n";
            out << "Адрес верный\n";
        }
        else
        {
            cout << "Адрес неверный\n";
            out << "Адрес неверный\n";
        }
    }
    delete[]MAC;
}


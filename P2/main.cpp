#include <stdio.h>
#include <iostream>
#include <string>
#include "/home/student/my_cplusplus_programs/Labtimp/Labtimp1/Zadanie2/program2/chifr.h"
using namespace std;

string encrypt(string input, const int key);
string decrypt(string input, const int key);

int main(int argc, char **argv)
{
    Chifr encoder;  // Изменено имя на Chifr
    const int COLS = 10;

    string publicMessage = "GERALTISRIVII";  // Переименовано для улучшения читаемости
    string privateMessage = encoder.encrypt(publicMessage, COLS);  // Изменено имя объекта на encoder
    string decodedMessage = encoder.decrypt(privateMessage, COLS);  // Переименовано для согласованности

    cout << publicMessage << endl;
    cout << privateMessage << endl;
    cout << decodedMessage << endl;

    return 0;
}

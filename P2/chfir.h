#pragma once
#include <string>
using namespace std;

class Chifr
{
public:
    string encrypt(string input, const int key);
    string decrypt(string input, const int key);
};

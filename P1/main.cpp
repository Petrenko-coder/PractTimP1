   #include <iostream>
#include <locale>
#include "/home/student/my_cplusplus_programs/Labtimp/Labtimp1/Zadanie1/program1/modAlphaCipher.h"

using namespace std;

void check(const wstring& text, const wstring& key)
{
    wstring cipherText;
    wstring decryptedText;
    modAlphaCipher cipher(key);
    
    cipherText = cipher.encrypt(text);
    decryptedText = cipher.decrypt(cipherText);
    
    wcout << L"key = " << key << endl;
    wcout << text << endl;
    wcout << cipherText << endl;
    wcout << decryptedText << endl;
    
    if (text == decryptedText)
        wcout << L"ok\n";
    else
        wcout << L"err\n";
}

int main(int argc, char **argv)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    
    check(L"СТАРОСТА", L"КИТ");
    
    return 0;
}

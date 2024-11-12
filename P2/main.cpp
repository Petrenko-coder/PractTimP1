#include <stdio.h>
#include <iostream>
#include <cctype>
#include "BetaCipher.h"
#include <locale>
using namespace std;
bool isValid(const wstring& s)
{
     for(auto c:s)
         if (!iswalpha(c) || !iswupper(c))
             return false;
     return true;
}
int main(int argc, char **argv)
{
    int key=3;
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring z;
    wstring text;
    unsigned op;
    wcout<<L"Cipher ready. Input please Password: ";
    wcin>>z;
    BetaCipher cipher(key);
    do {
        wcout<<L"Cipher ready. Input please operation (0-exit, 1-encrypt, 2-decrypt): ";
        wcin>>op;
        if (op > 2) {
            wcout<<L"Illegal operation\n";
        } else if (op >0) {
            wcout<<L"Cipher ready. Input please text: ";
          wcin>>text;
          if (isValid(text)) {
              if (op==1) {
                  wcout<<L"Encrypted text: 
"<<cipher.CoderBetaCipher(cipher, text)<<endl;
                     } else { 
                       wcout<<L"Decrypted text: 
"<<cipher.DecoderBetaCipher(cipher, text)<<endl;
                      }
                  } else {
                      wcout<<L"Operation aborted: invalid text\n";
                 }
            }
       } while (op!=0);
       return 0;
}

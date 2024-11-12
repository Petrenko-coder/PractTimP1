#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class BetaCipher
{
private:
   int p;
public:
   BetaCipher()=delete;
   BetaCipher(int w);
   wstring CoderBetaCipher(BetaCipher w, wstring& s);
   wstring DecoderBetaCipher(BetaCipher w, wstring& s);
};

    #include <iostream>
#include "modAlphaCipher.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

wstring numAlpha = L"АБВГДЕЖЗИКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
map<wchar_t, int> alphaNum;

modAlphaCipher::modAlphaCipher(const wstring& skey)
{
    for (size_t i = 0; i < numAlpha.size(); i++) {
        alphaNum[numAlpha[i]] = static_cast<int>(i);
    }
    key = convert(skey);
}

std::wstring modAlphaCipher::encrypt(const wstring& open_text)
{
    vector<int> work = convert(open_text);
    for (size_t i = 0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % static_cast<int>(alphaNum.size());
    }
    return convert(work);
}

wstring modAlphaCipher::decrypt(const wstring& cipher_text)
{
    vector<int> work = convert(cipher_text);
    for (size_t i = 0; i < work.size(); i++) {
        work[i] = (work[i] + static_cast<int>(alphaNum.size()) - key[i % key.size()]) % static_cast<int>(alphaNum.size());
    }
    return convert(work);
}

inline vector<int> modAlphaCipher::convert(const wstring& str)
{
    vector<int> result;
    for (const auto& c : str) {
        result.push_back(alphaNum.at(c));
    }
    return result;
}

inline wstring modAlphaCipher::convert(const vector<int>& v)
{
    wstring result;
    for (const auto& i : v) {
        result.push_back(numAlpha.at(i));
    }
    return result;
}

#include "BetaCipher.h"
BetaCipher::BetaCipher(int password)
{
    this->p=password;
}
wstring BetaCipher::CoderBetaCipher(BetaCipher w, wstring& s)
{
    wstring Output;
    int vis;
    int dlina=s.size();
    if (s.size()%w.p!=0) {
        vis=s.size()/w.p+1;
    } else {
        vis=s.size()/w.p;
    } 
    wchar_t x[vis][w.p]; 
    int p=0; 
    for (int i=0; I<vis; ++i) {
         for (int k=0; k<w.p; ++k) {
              if (p<s.length()) {
                  x[i][k]=s[p]; 
			   ++p; 
		    } else x[i][k]=' '; 
	    }
   } 
  for (int i=0; I<w.p; ++i) {
       for (int k=0; k<vis; ++k) {
          Output+=x[k][i]; 
       }
  }
  return Output; 
} 
wstring BetaCipher::DecoderBetaCipher(BetaCipher w, wstring& s) 
{ 
    int vis; 
    if (s.size()%w.p!=0) { 
        vis=s.size()/w.p+1; 
    } else { 
        vis=s.size()/w.p; 
    } 
    wchar_t x[vis][w.p]; 
    int p=0; 
    for (int i=0; I<w.p ++i) {
        for (int k=0; k<vis; ++k) {
            x[k][i]=s[p]; 
            ++p; 
        }
    }
    wstring deOutput; 
    for (int i=0; I<vis; ++i) {
        for (int k=0; k<w.p; ++k) {
             deOutput+=x[i][k]; 
        }
    } 
    return deOutput; 
}

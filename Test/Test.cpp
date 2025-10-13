#include <bits/stdc++.h>
using namespace std;

string S, temp;

int main()
{
    // 공백 포함 입력
    getline(cin, S); 
    
    for(int i = 0; i < S.length(); i++)
    {        
        if      (S[i] >= 'A' && S[i] <= 'Z') temp += ((S[i] - 'A' + 13) % 26 + 'A'); // 대문자
        else if (S[i] >= 'a' && S[i] <= 'z') temp += ((S[i] - 'a' + 13) % 26 + 'a'); // 소문자
        else                                 temp += S[i];                           // 공백 페스
    }
    
    cout << temp;
    
    return 0;
}
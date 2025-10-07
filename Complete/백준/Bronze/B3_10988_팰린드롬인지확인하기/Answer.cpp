#include<bits/stdc++.h>
using namespace std;

string originS, reverseS;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin >> originS;

    // 문자열 뒤집기
    reverseS = originS;
    reverse(reverseS.begin(), reverseS.end());

    // 팰린드롬 확인 및 출력
    if(reverseS == originS) cout << 1 << "\n";
    else                    cout << 0 << "\n";

    return 0;
}
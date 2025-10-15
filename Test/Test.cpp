#include<bits/stdc++.h>
using namespace std;

int                 N, M;
string              temp; 
map<string, int>    mp1;
map<int,    string> mp2;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M; 
    
    for(int i = 0; i < N; i++)
    {
        cin >> temp; 
        
        mp1[temp]  = i + 1; // 문자 키 - 숫자 값
        mp2[i + 1] = temp;  // 숫자 키 - 문자 값
    }
    
    for(int i = 0; i < M; i++)
    {
        cin >> temp; 
        
        // 문자가 들어온 경우
        // atoi 함수는 string을 int로 변경
        if(atoi(temp.c_str()) == 0)
        {
            cout << mp1[temp] << "\n";
        }
        // 숫자가 들어온 경우
        else
        {
            cout << mp2[atoi(temp.c_str())] << "\n"; 
        }
    }
}
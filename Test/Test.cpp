#include <bits/stdc++.h>
using namespace std;  

vector<int>  num;
vector<char> oper_str; 
int n, ret = -987654321;
string s;

// Operation 연산자(%는 문제에서 사용 안함)
int Oper(char a, int b, int c)
{
    if(a == '+') return b + c; 
    if(a == '-') return b - c; 
    if(a == '*') return b * c;  
} 

void Check(int here, int _num)
{
    if(here == num.size() - 1)
    { 
        ret = max(ret, _num); 
        return;
    }  
    Check(here + 1, Oper(oper_str[here], _num, num[here + 1]));

    if(here + 2 <= num.size() - 1)
    {
        int temp = Oper(oper_str[here + 1], num[here + 1], num[here + 2]); 
        Check(here + 2, Oper(oper_str[here], _num, temp));  
    } 
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);   
    
    cin >> n; // 입력 횟수
    cin >> s; // 입력 횟수 길이의 스트링
    
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0) num.push_back(s[i] - '0');
        else           oper_str.push_back(s[i]);
    }
    
    Check(0, num[0]);  
    cout << ret << "\n";
    
    return 0;
} 
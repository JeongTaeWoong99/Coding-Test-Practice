// 정답 코드
#include <bits/stdc++.h>
using namespace std;

const int MMAX = 200004;

int visited[MMAX];
int prevNUM[MMAX];
int n, k, ret, here, cnt, next;   
vector<int> v; 
queue<int>  q;  

int main()
{ 
    cin >> n >> k;
    
    visited[n] = 1;
    
    q.push(n);
    while(q.size())
    {
        here = q.front();  
        q.pop();
        
        if(here == k)
        {
            ret = visited[k]; 
            break;
        }
        
        for(int next : {here + 1, here - 1, here * 2})
        {
            if(next >= MMAX || next < 0 || visited[next]) continue;
            
            visited[next] = visited[here] + 1; 
            prevNUM[next] = here; 
            q.push(next); 
        } 
    }

    // 시간 출력
    cout << ret - 1 << '\n';

    // 경로 출력
    for(int i = k; i != n; i = prevNUM[i])
        v.push_back(i);
    v.push_back(n);
    reverse(v.begin(), v.end());
    for(int i : v)
        cout << i << ' ';
    
    return 0;
}
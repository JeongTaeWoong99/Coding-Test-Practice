// #include <bits/stdc++.h>
// using namespace std;
//
// int          K, M;           // K = 트리의 깊이, M = 총 노드 개수 (2^K - 1)
// vector <int> v[10];          // 레벨별 노드 저장 벡터 (v[0] = 루트, v[1] = 2레벨, ...)
// int          nodeArr[5000];  // 중위 순회 결과 배열
//
// // start : 배열의 시작 인덱스, end : 배열의 끝 인덱스, level : 현재 트리 레벨
// void Re(int start, int end, int level)
// {
//     // 범위가 유효하지 않으면 종료 (base case)
//     if (start > end) return;
//
//     // 중위 순회의 핵심: 중앙값이 현재 서브트리의 루트
//     int mid = (start + end) / 2;
//
//     // 현재 레벨에 루트 노드 추가
//     v[level].push_back(nodeArr[mid]);
//
//     // 왼쪽 서브트리 재귀 (start ~ mid-1 범위)
//     Re(start, mid - 1, level + 1);
//
//     // 오른쪽 서브트리 재귀 (mid+1 ~ end 범위)
//     Re(mid + 1, end, level + 1);
// }
//
// int main()
// {
//     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//
//     // 트리 깊이 입력
//     cin >> K;
//
//     // 노드 개수 계산 (2^K - 1)
//     M = 1;
//     for (int i = 0; i < K; i++) M *= 2;
//     M -= 1;
//
//     // 중위 순회 결과 입력
//     for (int i = 0; i < M; i++) cin >> nodeArr[i];
//
//     // 재귀 시작: 전체 배열 범위(0 ~ M-1), 레벨 0부터
//     Re(0, M - 1, 0);
//
//     // 레벨별 출력
//     for (int i = 0; i < K; i++)
//     {
//         for (auto j : v[i])
//             cout << j << " ";
//         cout << '\n';
//     }
//
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int         n;
int         a[1030];
vector<int> ret[14];

void go(int _start, int _end, int level)
{ 
    if(_start > _end) return;
    
    if(_start == _end)
    { 
        ret[level].push_back(a[_start]); 
        return;
    }
    
    int _mid = (_start + _end) / 2;
    ret[level].push_back(a[_mid]);
    
    go(_start  ,  _mid - 1, level + 1);
    go(_mid + 1, _end     , level + 1); 
}

int main()
{
    cin >> n;
    int _end = static_cast<int>(pow(2, n)) - 1;
    
    for(int i = 0; i < _end; i++)
        cin >> a[i];
    
    go(0, _end, 1); 

    for(int i = 1; i <= n; i++)
    {
        for(int j : ret[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
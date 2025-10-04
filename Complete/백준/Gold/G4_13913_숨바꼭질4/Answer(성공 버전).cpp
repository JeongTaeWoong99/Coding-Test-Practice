#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;

int N, K;
int visited[MAX + 4];  // 각 위치까지의 최소 시간
int parent[MAX + 4];   // 각 위치로 오기 전의 이전 위치
vector<int> v;         // 경로 저장용

int main()
{
    cin >> N >> K;

    // 반례
    if (N == K)
    {
        cout << "0" << '\n';
        cout << N;
        return 0;
    }

    visited[N] = 1;
    parent[N]  = -1;  // 시작 위치는 이전 위치가 없음

    queue<int> bfsQ;
    bfsQ.push(N);

    while (!bfsQ.empty())
    {
        int now = bfsQ.front();
        bfsQ.pop();

        // K에 도달하면 종료
        if (now == K)
        {
            break;
        }

        // 3가지 이동: X - 1, X + 1, X * 2
        for (int next : {now - 1, now + 1, now * 2})
        {
            // 범위 체크
            if (next < 0 || next > MAX) continue;

            // 처음 방문하는 경우
            if (!visited[next])
            {
                bfsQ.push(next);                   // 큐에 추가
                visited[next] = visited[now] + 1;  // 시간 갱신
                parent[next]  = now;               // 이전 위치 기록
            }
        }
    }

    // 시간 출력
    cout << visited[K] - 1 << '\n';
    
    // 경로 출력
    for(int i = K; i != N; i = parent[i])  // 역추적 경로 넣기
        v.push_back(i);
    v.push_back(N);
    reverse(v.begin(), v.end());  // 뒤집기 (N -> K)
    for(int i : v)                          // 출력
        cout << i << ' ';

    return 0;
}

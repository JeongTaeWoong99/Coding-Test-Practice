#include <bits/stdc++.h>
using namespace std;

const int  MAX = 200000; // N과 K의 최대는 100000 이지만, X*2 순간이동으로 인해 범위를 초과할 수 있기 때문에, 여유롭게 2배로 설정

int        visited[MAX+4]; // visited : 각 위치까지 도달하는 최소 시간 (1 이상은 방문 및 시간 기록, 0은 미방문)
long long  pathNum[MAX+4]; // pathNum : 각 위치까지 최소 시간으로 도달하는 방법의 수
int        N, K;           // N: 수빈이의 위치, K: 동생의 위치
queue<int> Q;              // BFS 큐

int main()
{
    cin >> N >> K;

    // 반례 
    if(N == K)
    {
        cout << "0" << '\n';
        cout << "1";
        return 0;
    }

    // 시작 위치 초기화
    visited[N] = 1; // 시작 위치
    pathNum[N] = 1; // 방법 수

    // 시작 위치 BFS 큐 추가
    Q.push(N);
    while (!Q.empty())
    {
        // 현재값 추출
        int now = Q.front();
        Q.pop();

        // 3가지 이동: X - 1, X + 1, X * 2
        // ☆ next는 차례로 3가지 값을 가지고, 3번 실행됨
        for (int next : {now - 1, now + 1, now * 2})
        {
            // 범위 안 인지 확인
            if (0 <= next && next <= MAX)
            {
                // 처음 방문하는 경우
                if (!visited[next])
                {
                    Q.push(next);                      // 큐에 넣기
                    visited[next] = visited[now] + 1;  // 최소 시간 갱신
                    pathNum[next] = pathNum[now];      // 경로 갱신
                }
                // 같은 시간에 도달하는 다른 경로
                else if (visited[next] == visited[now] + 1)
                {
                    pathNum[next] += pathNum[now]; // 경로 수 누적(다른 경로로 도달했기 때문에)
                }
            }
        }
    }

    cout << visited[K] - 1 << '\n'; // 최소 시간 출력 (-1 보정)
    cout << pathNum[K];             // 방법의 수 출력

    return 0;
}

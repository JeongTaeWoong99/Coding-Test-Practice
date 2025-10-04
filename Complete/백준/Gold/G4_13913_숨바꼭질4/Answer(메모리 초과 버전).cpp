#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;

int    N, K;
int    visited[MAX + 4];
string strPath[MAX + 4];

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

    visited[N]  = 1;
    strPath[N]  = to_string(N) + " ";

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
                bfsQ.push(next);                                           // 큐에 추가
                visited[next] = visited[now] + 1;                          // 시간 갱신
                strPath[next] = strPath[now] + to_string(next) + " ";      // 경로 누적 (메모리 초과 원인!)
            }
        }
    }

    cout << visited[K] - 1 << '\n';
    cout << strPath[K];

    return 0;
}

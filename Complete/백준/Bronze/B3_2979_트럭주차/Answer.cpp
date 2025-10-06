#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int arrive, leave;
int cnt[104], ret;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> A >> B >> C;                            // 트럭 1대, 2대, 3대일 때의 분당 요금 입력

    for(int i = 0; i < 3; i++)                     // 3대의 트럭에 대해 반복
    {
        cin >> arrive >> leave;                    // 각 트럭의 도착 시간과 떠난 시간 입력

        for(int j = arrive; j < leave; j++)        // 도착 시간부터 떠난 시간 전까지 반복 (떠난 시간은 포함하지 않음)
            cnt[j]++;                              // 해당 시간대에 주차된 트럭 개수 증가
    }

    for(int j = 1; j < 100; j++)                   // 1분부터 99분까지 반복
    {
        if(cnt[j])                                 // 해당 시간대에 주차된 트럭이 있다면
        {
                 if(cnt[j] == 1) ret += A * 1;     // 1대일 때: A * 1
            else if(cnt[j] == 2) ret += B * 2;     // 2대일 때: B * 2
            else if(cnt[j] == 3) ret += C * 3;     // 3대일 때: C * 3
        }
    }

    cout << ret << "\n";                           // 총 주차 요금 출력

    return 0;
}
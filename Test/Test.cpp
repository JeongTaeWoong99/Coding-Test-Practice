// 내코드
#include <bits/stdc++.h>
using namespace std;

int N, K, temp, sum = 0, maxSum;
int arr[100000];

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> N >> K;

    // 입력 받기
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // 처음 K개의 합 구하기
    for (int i = 0; i < K; i++)
    {
        sum += arr[i];
    }
    maxSum = sum; // 초기 최대값 설정

    // 슬라이딩 윈도우: K번째부터 N-1번째까지
    for (int i = K; i < N; i++)
    {
        sum += arr[i];       // 새로운 원소 추가
        sum -= arr[i - K];   // 맨 앞 원소 제거
        maxSum = max(maxSum, sum); // 최대값 갱신
    }

    cout << maxSum << "\n";
    return 0;
}


// 강사 코드
// #include<bits/stdc++.h> 
// using namespace std;  
//
// // <맞왜틀 피하는 방법>
// // 2 ~ 100000 입력 -> psum[100001]
// // 입력되는 값의 범위 -100 이상 100 이하
// // ret 그러므로, 최대값은 -100 * 100000 = -1000000 부터 시작
// int n, k, temp, psum[100001], ret = -1000000; 
//
// int main()
// {
//     cin >> n >> k; 
//     
//     // 누적합 구하기
//     for(int i = 1; i <= n; i++)
//     {
//         cin >> temp; 
//         psum[i] = psum[i - 1] + temp; 
//     }
//     
//     // 필요없는 부분 없애주기
//     for(int i = k; i <= n; i++)
//     {
//         //max는 둘 중, 더 큰 수를 선택하는 내장 라이브러리.
//         ret = max(ret, psum[i] - psum[i - k]);
//     }
//     
//     cout << ret;
//     
//     return 0;
// }
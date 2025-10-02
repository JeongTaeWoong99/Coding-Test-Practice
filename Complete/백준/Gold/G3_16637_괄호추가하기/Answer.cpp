#include <bits/stdc++.h>
using namespace std;  

vector<int>  numVec;   // 수식에서 숫자들을 저장  (예 : "3+8*7-9*2"   → [3, 8, 7, 9, 2])
vector<char> operVec;  // 수식에서 연산자들을 저장 (예 : "3+8*7-9*2"  → ['+', '*', '-', '*'])
int          ret;      // 괄호를 추가했을 때 나올 수 있는 최댓값을 저장
int          n;        // 수식의 길이
string       s;        // 입력받은 수식 문자열

// 두 숫자 b, c를 연산자 a로 연산하는 함수
// operation : 연산자 (+, -, *)(%는 현재 문제에서 사용 안함)
// b         : 왼쪽 피연산자
// c         : 오른쪽 피연산자
int Oper(char operation, int a, int b)
{
    if(operation == '+') return a + b; // 덧셈
    if(operation == '-') return a - b; // 뺄셈
    if(operation == '*') return a * b; // 곱셈
} 

// 재귀를 통해 모든 괄호 조합을 탐색하는 함수
// here : 현재 처리 중인 숫자의 인덱스 (num 배열 기준)
// _num : 현재까지 계산된 결과값
void Check(int here, int _num)
{
    // 기저 사례: 마지막 숫자까지 도달했을 때
    if(here == numVec.size() - 1)
    {
        ret = max(ret, _num); // 현재 결과와 최댓값 비교 후 갱신
        return;
    }

    // 경우 1 : 괄호 없이 그냥 다음 숫자와 계산(값 계산 및 누적하여, 다음 자리로 넘어감)
    // 예: 3 + 8 * 7 에서 "3 + 8"을 먼저 계산 (왼쪽부터 순서대로)
    Check(here + 1, Oper(operVec[here], _num, numVec[here + 1]));
    
    // 경우 2: 다음 연산을 괄호로 묶어서 먼저 계산
    // 예: 3 + (8 * 7) 처럼 오른쪽을 먼저 계산
    if(here + 2 <= numVec.size() - 1)
    {
        // 다음 두 숫자를 먼저 계산 (괄호 안의 연산)
        int temp = Oper(operVec[here + 1], numVec[here + 1], numVec[here + 2]);
        
        // 현재 결과와 괄호 안의 결과를 계산하고 재귀 호출
        Check(here + 2, Oper(operVec[here], _num, temp));
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    // 입력 처리
    cin >> n; // 수식의 길이 (1 ≤ n ≤ 19, 홀수)
    cin >> s; // 수식 문자열 (예: "3+8*7-9*2")

    // 수식 파싱 : 숫자와 연산자 분리
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0) numVec.push_back(s[i] - '0'); // 짝수 인덱스 → 숫자 저장
        else           operVec.push_back(s[i]);         // 홀수 인덱스 → 연산자 저장
    }
    
    // 재귀 탐색 시작: 첫 번째 숫자부터 시작
    Check(0, numVec[0]);

    // 결과 출력
    cout << ret << "\n";

    return 0;
}
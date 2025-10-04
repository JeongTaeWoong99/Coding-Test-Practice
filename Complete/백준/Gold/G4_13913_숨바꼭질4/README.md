**📅 작성일**: 2025-10-04

## 🔗 문제 링크
[백준 13913번 - 숨바꼭질 4](https://www.acmicpc.net/problem/13913)

---

## 🤔 접근법

순박꼭질 2의 응용 문제였다.

BFS에다가 string 배열에 경로를 누적하는 방식으로 했는데, 메모리 초과가 났다.

그래서, int 배열에 이전 위치를 값을 저장해서, 가르키는 방식으로 해결했다.

---

## 💡 정답 풀이 방법

**알고리즘**: BFS (너비 우선 탐색) + 역추적 (Backtracking)

**핵심 아이디어**:
```
1. BFS로 최단 시간을 구하면서, 각 위치의 이전 위치를 parent 배열에 기록
2. 목적지 K에 도달하면 parent 배열을 역추적하여 경로 복원
3. 역추적한 경로를 reverse()로 뒤집어서 N → K 순서로 출력
```

**시간 복잡도**: O(N)
- BFS 탐색: O(N) (최대 200,000개 위치 방문)
- 경로 역추적: O(경로 길이) ≈ O(logN)

**공간 복잡도**: O(N)
- visited 배열: O(N)
- parent 배열: O(N)
- BFS 큐: O(N)
- 경로 벡터: O(경로 길이) ≈ O(logN)

---

## 🔑 주요 구현 포인트

### 1️⃣ 자료구조 설계
```cpp
int visited[MAX + 4];  // 각 위치까지의 최소 시간 (0: 미방문, 1~: 시간+1)
int parent[MAX + 4];   // 각 위치로 오기 전의 이전 위치 (역추적용)
vector<int> v;         // 경로 저장용 벡터
```

**✅ 핵심**: string 배열 대신 int 배열 사용으로 메모리 효율 대폭 개선
- string 배열: 수십 MB (경로 전체를 문자열로 저장)
- int 배열: 800 KB (이전 위치만 정수로 저장)

### 2️⃣ BFS 탐색 중 경로 기록
```cpp
for (int next : {now - 1, now + 1, now * 2})
{
    if (next < 0 || next > MAX) continue;

    if (!visited[next])
    {
        bfsQ.push(next);                   // 큐에 추가
        visited[next] = visited[now] + 1;  // 시간 갱신
        parent[next]  = now;               // 이전 위치 기록 ⭐
    }
}
```

**✅ 핵심**: `parent[next] = now`로 현재 위치에서 next로 이동했음을 기록

### 3️⃣ 경로 역추적 (Backtracking)
```cpp
// K부터 N까지 역으로 추적
for(int i = K; i != N; i = parent[i])
    v.push_back(i);
v.push_back(N);

// N → K 순서로 뒤집기
reverse(v.begin(), v.end());

// 출력
for(int i : v)
    cout << i << ' ';
```

**✅ 핵심**:
- K에서 시작해서 parent[i]를 따라가면 N까지 도달
- 역순이므로 reverse()로 뒤집어서 정방향 경로 생성

### 4️⃣ 반례 처리
```cpp
if (N == K)
{
    cout << "0" << '\n';
    cout << N;
    return 0;
}
```

**✅ 핵심**: 시작 위치와 목적지가 같은 경우 바로 종료
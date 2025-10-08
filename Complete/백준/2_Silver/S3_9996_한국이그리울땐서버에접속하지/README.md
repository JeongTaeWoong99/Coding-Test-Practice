**📅 작성일**: 2025-10-08

## 🔗 문제 링크
[백준 9996번 - 한국이 그리울 땐 서버에 접속하지](https://www.acmicpc.net/problem/9996)

---

## 🤔 접근법
패턴 매칭 문제. 

`*`를 기준으로 앞뒤 문자열을 분리해서 파일명과 비교.

패턴은 'ab*cd', 'h*n' 등등 길이 100까지 올 수 있음을 생각.

---

## 💡 정답 풀이 방법

1. **패턴 분리**: `find('*')`로 `*` 위치를 찾아 앞부분(prefix)과 뒷부분(suffix) 분리

2. **길이 검증**: 파일명 길이가 `prefix + suffix` 길이보다 짧으면 무조건 NE

3. **문자열 비교**:
   - 파일명의 앞부분이 `prefix`와 일치하는지 확인
   - 파일명의 뒷부분이 `suffix`와 일치하는지 확인

4. **핵심**: `char` 타입이 아닌 `string` 타입으로 전체 문자열을 저장해야 함

---

## 🔑 핵심 개념

**substr() 함수 활용**
```cpp
int pos = ori_s.find('*');         // * 위치 찾기
pre = ori_s.substr(0, pos);        // 0부터 pos개 추출
suf = ori_s.substr(pos + 1);       // pos+1부터 끝까지 추출
```

**패턴 매칭 조건**
- 길이: `pre.size() + suf.size() <= s.size()`
- 앞부분: `pre == s.substr(0, pre.size())`
- 뒷부분: `suf == s.substr(s.size() - suf.size())`

---

**⏱️ 시간복잡도**: O(N × M) - N개 파일, 각 파일명 길이 M

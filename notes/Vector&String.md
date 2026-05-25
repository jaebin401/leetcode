# Vector & String Cheatsheet

LeetCode 문제 풀면서 자주 틀리거나 헷갈렸던 내용 정리.

---

## 1. Python 문법 혼동 주의

C++에 없는 Python 문법을 무의식적으로 쓰는 경우가 많음.

```cpp
// 슬라이싱
string part = small[0:i];           // ❌ Python
string part = small.substr(0, i);   // ✅ C++

// 빈 컨테이너 초기화
vector<int> info = [];              // ❌ Python
vector<int> info;                   // ✅ C++

// 리스트 리터럴
vector<char> V = [a, e, i, o, u];           // ❌ Python
vector<char> V = {'a', 'e', 'i', 'o', 'u'}; // ✅ C++

// 원소 추가
info.append(i);                     // ❌ Python
info.push_back(i);                  // ✅ C++
```

---

## 2. 존재하지 않는 함수들

C++에 있을 거라 가정하고 썼다가 컴파일 에러난 함수들.

```cpp
s.pop()        // string에 pop() 없음 → s.pop_back()
s.reverse()    // string에 reverse() 없음 → reverse(s.begin(), s.end())
v.find(x)      // vector에 find() 없음 → find(v.begin(), v.end(), x)
v.append(x)    // vector에 append() 없음 → v.push_back(x)
max(v)         // max에 vector 직접 못 넣음 → *max_element(v.begin(), v.end())
```

기억할 것: **STL의 알고리즘 함수들은 컨테이너를 직접 받지 않고, `begin()`/`end()` iterator로 범위를 받음.**

---

## 3. char vs string 타입

작은따옴표와 큰따옴표는 완전히 다른 타입.

```cpp
'a'   // char    (문자 하나)
"a"   // string  (문자열)
```

자주 한 실수:

```cpp
char temp = "";        // ❌ char에 string 대입
char temp = '\0';      // ✅

s[0] = "H";            // ❌ s[i]는 char인데 string 대입
s[0] = 'H';            // ✅

vowels += "0";         // ❌ char 의도면 의미 모호
vowels += '0';         // ✅
```

---

## 4. 잘못된 연산자

```cpp
if (back => 0)         // ❌ => 는 없음
if (back >= 0)         // ✅

if (n =< 10)           // ❌ =< 는 없음
if (n <= 10)           // ✅

s -= "world";          // ❌ string에 -= 없음
s.erase(pos, len);     // ✅ 제거는 erase

while (!s == "")       // ❌ !s가 먼저 평가됨
while (s != "")        // ✅
```

---

## 5. 연산자 우선순위 — 괄호 명시 습관

```cpp
if (temp.size() % i+1 == 0)
// 실제 해석: ((temp.size() % i) + 1) == 0   ❌

if (temp.size() % (i+1) == 0)                // ✅
```

`%`, `&&`, `||` 주변엔 의도를 명확히 하기 위해 괄호 쓰기.

---

## 6. 포인터 역참조 `*` 와 매개변수 `&`

둘은 별개의 개념.

```cpp
// 매개변수의 & — 복사 없이 원본 직접 받기
void func(vector<int>& v)

// 포인터/iterator 앞의 * — 가리키는 값 꺼내기
int maxVal = *max_element(v.begin(), v.end());
//           ↑
//   max_element는 iterator 반환
//   *로 역참조해야 값을 꺼낼 수 있음
```

---

## 7. STL 함수에 vector 전달하는 방식

```cpp
sort(v);                    // ❌
sort(v.begin(), v.end());   // ✅

reverse(v);                          // ❌
reverse(v.begin(), v.end());         // ✅

find(v, x);                          // ❌
find(v.begin(), v.end(), x);         // ✅
```

**범위(begin, end)를 전달하는 것이 STL의 표준 패턴.**

---

## 8. 인덱스 범위 초과 방어

`i-1`, `i+1` 접근할 땐 항상 범위 체크 먼저.

```cpp
// ❌ i가 마지막일 때 크래시
if (flowerbed[i] == 1 && flowerbed[i+1] == 0)

// ✅ 범위 체크 먼저
if (i+1 < length && flowerbed[i] == 1 && flowerbed[i+1] == 0)

// ✅ 단락 평가 활용 (||의 왼쪽이 true면 오른쪽 안 봄)
bool rightEmpty = (i == length-1) || (flowerbed[i+1] == 0);
```

---

## 9. 원본 배열 수정 주의

루프 안에서 원본을 수정하면 다음 반복의 비교 기준이 오염됨.

```cpp
// ❌ 매 루프마다 maxVal이 바뀜
for (int i = 0; i < n; i++) {
    candies[i] = candies[i] + extraCandies;
    int maxVal = *max_element(candies.begin(), candies.end());
}

// ✅ 임시 변수 + 루프 전 최댓값 계산
int currentMax = *max_element(candies.begin(), candies.end());
for (int i = 0; i < n; i++) {
    int total = candies[i] + extraCandies;
    result[i] = (total >= currentMax);
}
```

---

## 10. vector 초기화 혼용 버그

```cpp
// ❌ 크기 지정 + push_back 혼용 → 크기 2배
vector<bool> kids(candies.size());  // false × 5
kids.push_back(true);                // 뒤에 추가 → 크기 6

// ✅ 둘 중 하나만
vector<bool> kids;                   // 빈 벡터 → push_back
vector<bool> kids(candies.size());   // 크기 고정 → kids[i] = ...
```

---

## 핵심 패턴 빠르게 보기

| 작업 | 코드 |
|------|------|
| 빈 벡터 선언 | `vector<T> v;` |
| 크기 지정 초기화 | `vector<T> v(n);` 또는 `vector<T> v(n, val);` |
| 원소 추가 | `v.push_back(x);` |
| 맨 뒤 제거 | `v.pop_back();` |
| 벡터 최댓값 | `*max_element(v.begin(), v.end())` |
| 벡터에서 찾기 | `find(v.begin(), v.end(), x) != v.end()` |
| 정렬 | `sort(v.begin(), v.end());` |
| 뒤집기 | `reverse(v.begin(), v.end());` |
| 문자열 슬라이싱 | `s.substr(start, len)` |
| 문자열에서 찾기 | `s.find(target) != string::npos` |
| 문자열 제거 | `s.erase(pos, len)` |
| 특정 문자열 전부 제거 | `while ((pos = s.find(t)) != npos) s.erase(pos, t.size());` |
| 문자 vs 문자열 | `'a'` (char) vs `"a"` (string) |

---

## GCD 관련 (보너스)

```cpp
#include <numeric>

gcd(8, 4);   // 4
gcd(6, 4);   // 2
gcd(7, 5);   // 1
```

C++17부터 표준 지원. 유클리드 호제법 직접 구현할 필요 없음.
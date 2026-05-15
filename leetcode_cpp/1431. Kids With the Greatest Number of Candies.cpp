// 1431. Kids With the Greatest Number of Candies
// URL        : https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
// Difficulty : Easy
// Date       : 2026.05.15
//
// [Approach]
// 1. 원본 배열에서 최댓값을 먼저 구해둠
// 2. 각 아이에게 extraCandies를 몰빵했을 때 최댓값 이상이 되는지 확인
// Time: O(n) / Space: O(n)
//
// [What I learned]
//
// 1. max_element() — vector에서 최댓값 찾기
//    - 반환값이 값이 아니라 iterator(포인터)이므로 * 로 역참조 필요
//    - int maxVal = *max_element(v.begin(), v.end());
//    - max(v) 처럼 vector를 직접 넣는 건 불가능
//
// 2. 포인터 역참조 * 와 참조 매개변수 & 는 별개
//    - & (매개변수): 복사 없이 원본을 직접 받겠다는 선언
//      예) void func(vector<int>& v)
//    - * (포인터 앞): 포인터가 가리키는 값을 꺼냄 (역참조)
//      예) *max_element(v.begin(), v.end())
//    - 둘은 서로 관계없음
//
// 3. vector 초기화 방식
//    - vector<bool> result(n)     : 크기 n, 전부 false로 초기화 → result[i] = 로 접근
//    - vector<bool> result        : 빈 벡터 → push_back()으로 채움
//    - 두 방식을 혼용하면 크기가 2배가 되는 버그 발생

// 모범답안

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int currentMax = *max_element(candies.begin(), candies.end());
        vector<bool> result(n);

        for (int i = 0; i < n; i++) {
            int total = candies[i] + extraCandies;
            result[i] = (total >= currentMax);
        }

        return result;
    }
};

// == 내 풀이 ==

// class Solution {
// public:
//     vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
//         int n = candies.size();

//         vector<bool> result(n);

//         // for문 시작, 사이즈는 n
//         for (int i = 0; i < n; i++) {
//             int currentMax = candies[i] + extraCandies;
//             candies[i] = currentMax;
//             // 현재 벡터의 최댓값 추출
//             int maxAmongVector = *max_element(candies.begin(), candies.end());
//             result[i] = (maxAmongVector <= currentMax);
//             candies[i] -= extraCandies;
//         }

//         return result;
//     }
// };
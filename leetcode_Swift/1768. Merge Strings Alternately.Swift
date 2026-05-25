// 1768. Merge Strings Alternately
// URL        : https://leetcode.com/problems/merge-strings-alternately/
// Difficulty : Easy
// Date: 2026.05.15.
//
// 배운것:
// 0. 변수 선언: var a: Int = 0
//    반복문 for i in 0..<n { ... }  // 0부터 n-1까지 반복
//    Swift는 기본적으로 max(a, b) 함수 제공
//
// 1. Swift String은 정수 인덱싱 불가 → Array()로 변환 후 인덱스 접근
//    let chars = Array(word)  // [Character]
//
// 2. 인덱스 범위 체크는 i < chars.count 로
//
// 3. zip(seq1, seq2) → 두 시퀀스를 짝지어 순회, 짧은 쪽 기준으로 자동 종료
//    for (c1, c2) in zip(word1, word2)
//
// 4. dropFirst(n) → 앞에서 n개 제거한 나머지 반환
//    String(word1.dropFirst(minCount))

// ==== 모범 답안 ====

class Solution {
    func mergeAlternately(_ word1: String, _ word2: String) -> String {
        var result = ""

        for (c1, c2) in zip(word1, word2) {
            result.append(c1)
            result.append(c2)
        }

        let minCount = min(word1.count, word2.count)
        result += String(word1.dropFirst(minCount))
        result += String(word2.dropFirst(minCount))

        return result
    }
}

// ==== 내 풀이 ====
class Solution {
    func mergeAlternately(_ word1: String, _ word2: String) -> String {
        let chars1 = Array(word1)
        let chars2 = Array(word2)
        let iter = max(chars1.count, chars2.count)
        var result: String = ""
        
        for i in 0..<iter {
            if i < chars1.count {
                result.append(chars1[i])
            }
            if i < chars2.count {
                result.append(chars2[i])
            }
        }
        return result
    }
}

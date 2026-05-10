// 1768. Merge Strings Alternately
// URL        : https://leetcode.com/problems/merge-strings-alternately/description/?envType=study-plan-v2&envId=leetcode-75
// Difficulty : Easy

// 배운것:
// 문자열의 크기 측정하는 방법: string.size() 또는 string.length()
// 문자열을 합치는 방법: string += char 또는 string += string
// 문자열의 특정 위치에 접근하는 방법: string[index]
// 정수의 최대값을 구하는 방법: max(a, b) 또는 std::max(a, b)
// C++에 pop()은 없다


#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int maxSize = max(word1.size(), word2.size());

        for (int i = 0; i < maxSize; i++) {
            if (i < word1.size()) result += word1[i];
            if (i < word2.size()) result += word2[i];
        }

        return result;
    }
};
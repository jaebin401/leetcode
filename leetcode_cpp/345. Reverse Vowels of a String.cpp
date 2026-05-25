// 345. Reverse Vowels of a String
// URL        : https://leetcode.com/problems/reverse-vowels-of-a-string/
// Difficulty : Easy
// Date       : 2026.05.25
//
// 배운것: 
// 1. 벡터는 push_back() 함수를 사용하여 요소를 추가할 수 있다. (append()는 C++에서는 사용되지 않는다.)
// 2. 문자열을 역전하는 방법: reverse(문자열 시작 인덱스, 문자열 끝 인덱스);
// 3. 문자열의 특정 인덱스를 문자로 바꿀 수 있다. 다만, 큰 따옴표가 아닌 작은 따옴표로 해야함
// 


// =============== 내 코드 ===============

class Solution {
public:
    string reverseVowels(string s) {
        int len = s.length();
        vector<int> info = [];
        string vowels = "aeiou";
        string V = "";

        for (int i = 0; i<len; i++) {
            if (// s[i]가 vowels 안에 있다면) 
            {
                info.append(i); // info에 해당 vowel의 인덱스 저장
                V += s[i];
            }
        }

        // V 문자열 reverse

        for (int j = 0; j<V.size(); j++) {
            // 이제 V와 info 매칭, s에 삽입
            s[info[j]] = V[j];
        }


        return s;
    }
};


// =============== 모범 답안 ===============
class Solution {
public:
    string reverseVowels(string s) {
        int len = s.length();
        vector<int> info;
        string vowels = "aeiouAEIOU";  // 대문자도 포함
        string V = "";

        for (int i = 0; i < len; i++) {
            if (vowels.find(s[i]) != string::npos) {
                info.push_back(i);
                V += s[i];
            }
        }

        reverse(V.begin(), V.end());

        for (int j = 0; j < V.size(); j++) {
            s[info[j]] = V[j];
        }

        return s;
    }
};
// 1071. Greatest Common Divisor of Strings
// URL        : https://leetcode.com/problems/greatest-common-divisor-of-strings/description/?envType=study-plan-v2&envId=leetcode-75
// Difficulty : Easy
// Date : 2026.05.13
//
// 내가 생각한 알고리즘: 겹쳐있는 문자열을 찾을 때, 작은 크기의 문자열들에서 공통분모를 찾고 그것이 큰 문자열의 공통분모가 되는지 확인하는 방법을 사용했다.
// 모범답안: str1 + str2 == str2 + str1 이면, 더 살펴보고 이게 아니면 바로 retrun ""
//         그리고 이제 더 살펴봐야 하는 경우에는, 최대공약수 gcd 함수를 사용하면 그냥 되더라
//
// 배운것
// 1. 문자열의 일부를 슬라이싱하는법: string part = small.substr(0, i);  // 0번부터 i개 문자
// 2. 삼항연산자 문법 => 조건 ? 참일때값 : 거짓일때값 string large = (str1.size() >= str2.size()) ? str1 : str2;
// 3. 최대공약수 찾아주는 함수: #include <numeric>의 std::gcd

#include <string>
#include <numeric>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // 공통 단위가 존재하는지 확인
        // 존재한다면 str1 + str2 == str2 + str1 이 반드시 성립
        if (str1 + str2 != str2 + str1) return "";

        // 공통 단위의 길이 = 두 문자열 길이의 GCD
        int gcdLen = gcd(str1.size(), str2.size());

        return str1.substr(0, gcdLen);
    }
};

//=================== 내가 생각했던 방식 ===================

/*
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        string large = (str1.size() >= str2.size()) ? str1 : str2;
        string small = (large == str1) ? str2 : str1;

        // small의 최소 반복 단위 찾기
        int smallSize = small.size();
        string unit = "";

        for (int i = 1; i <= smallSize; i++)
        {
            if (smallSize % i == 0)
            {
                string part = small.substr(0, i);
                string temp = small;

                // temp에서 part를 전부 제거
                size_t pos;
                while ((pos = temp.find(part)) != string::npos) {
                    temp.erase(pos, part.size());
                }

                if (temp == "") {
                    unit = part;
                    break;  // 가장 작은 단위 찾으면 종료
                }
            }
        }

        if (unit == "") return "";

        // large에서 unit을 전부 제거했을 때 ""이 되면 unit 반환
        string large_temp = large;
        size_t pos;
        while ((pos = large_temp.find(unit)) != string::npos) {
            large_temp.erase(pos, unit.size());
        }

        return (large_temp == "") ? unit : "";
    }
};

*/
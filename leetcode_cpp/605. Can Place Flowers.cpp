// 605. Can Place Flowers
// URL        : 
// Difficulty : 
// Date: 2026.05.24
//
// 배운것:
// - 인덱싱을 할 때, i-1, i+1이 범위를 벗어날 수 있기 때문에, 범위를 체크하는 조건을 늘 예민하게 추가해야 한다.
// - 문제에서 요구하는 조건을 꼼꼼히 읽어야 한다. (꽃을 심을 수 있는지 여부를 판단하는 문제이므로, 꽃을 심는 조건이 무엇인지 정확히 이해해야 한다.)
// - greedy algorithm이 필요한 문제였다. (꽃을 심을 수 있는 곳이 있다면, 최대한 빨리 심는 것이 최적의 해답이 된다.)
// - 꽃을 심는 조건을 체크하는 부분에서, leftEmpty와 rightEmpty를 따로 체크하는 것이 더 명확하고 오류를 줄이는 방법이었다. 
//
// 총평:

// ===== 내 코드 =====
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int newFlowers = n;
        int length = flowerbed.size();

        // flowerbed 벡터 한번 쭉 훝기
        for (int i = 0; i<length; i++) {

            // 만약 i번째는 1, i+1 번쩨 원소가 0이면, flowerbed[i+1] = 1
            if ((flowerbed[i] == 1) && (flowerbed[i+1] == 0)) {
                flowerbed[i+1] = 1;
                newFlowers -= 1;
            }
        }

        return newFlowers <= 0;
    }
};


// ==== 모범 답안 ====

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int length = flowerbed.size();

        for (int i = 0; i < length; i++) {
            bool leftEmpty  = (i == 0) || (flowerbed[i-1] == 0);
            bool rightEmpty = (i == length-1) || (flowerbed[i+1] == 0);

            if (flowerbed[i] == 0 && leftEmpty && rightEmpty) {
                flowerbed[i] = 1;
                n--;
            }

            if (n == 0) return true;
        }

        return false;
    }
};
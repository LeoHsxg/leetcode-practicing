#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/*
 ### 噴水池
 給定一個 1d 陣列，代表各點的高度。同時再給陣列 fountian 代表各噴水池位置
 而噴水池的水會往低處與同高度處流。回傳求有水流過的地塊 (不包含噴水池)
 (也可以說是噴水池不噴當前此格，這樣子噴水池的點位答案會略有不同 =>
    但這種似乎要額外維護水流 vis 去判斷，感覺格外麻煩)

 input:
    terrain = {1, 3, 2, 5, 1, 2, 1, 1}
    fountain = {1, 5}
    1, 3, 3, -1, -1, 2, 2, 2
    3, 3, 3, -1, 2, 2, 2, 2
 output:
    ans = {0, 0, 1, 0, 1, 0, 1, 1}
*/

class Solution {
   public:
    vector<int> twoPassPropagation(vector<int>& terrain, vector<int>& fountain) {
        int n = terrain.size();
        int flood;
        vector<int> waterLevel(n, -1);  // 先預設每個點都是無效水位
        vector<int> ans(n, 0);

        for (int f : fountain) {
            waterLevel[f] = terrain[f];  // 水位被噴水池給限制了
            ans[f] = -1;
        }
        for (int i = 1; i < n; i++) {
            // 左邊的水位是否能往右淹，要取決於當前位置的高度
            if (waterLevel[i - 1] >= terrain[i]) {
                waterLevel[i] = max(waterLevel[i], waterLevel[i - 1]);
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (waterLevel[i + 1] >= terrain[i]) {
                waterLevel[i] = max(waterLevel[i], waterLevel[i + 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] == -1) {
                ans[i] = 0;
                continue;
            }
            if (waterLevel[i] >= terrain[i]) {
                ans[i] = 1;
            }
        }
        return ans;
    }

    vector<int> dpAndTopoSort(vector<int>& terrain, vector<int>& fountain) {
        int n = terrain.size();
        vector<pair<int, int>> fountain_map;  // height, position
        vector<int> water(n, 0);

        for (int f : fountain) {
            fountain_map.push_back({terrain[f], f});
        }
        sort(fountain_map.begin(), fountain_map.end());

        for (int i = fountain.size() - 1; i >= 0; i--) {
            int h = fountain_map[i].first;
            int index = fountain_map[i].second;
            // traverse right side
            for (int j = index + 1; j < n; j++) {
                if (water[j] == 1)
                    break;
                if (h < terrain[j])
                    break;
                water[j] = 1;
            }
            // traverse left side
            for (int j = index - 1; j >= 0; j--) {
                if (water[j] == 1)
                    break;
                if (h < terrain[j])
                    break;
                water[j] = 1;
            }
        }

        return water;
    }
};

int main() {
    Solution sol;
    vector<int> terrain = {1, 3, 2, 5, 1, 2, 1, 1};
    vector<int> fountain = {1, 5};
    // vector<int> ans = sol.twoPassPropagation(terrain, fountain);
    vector<int> ans = sol.dpAndTopoSort(terrain, fountain);
    for (int a : ans) {
        cout << a << " ";
    }
    cout << endl;
}
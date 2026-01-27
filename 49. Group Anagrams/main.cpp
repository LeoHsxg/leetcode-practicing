#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// 49. Group Anagrams
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_set<unordered_map<string, int>> strs_set;
        // unordered_set<string> str_set;
        // map<char, int> let_cnt; // letters count
        // string tmpS;
        // for (string str : strs) {
        //     for (char c : str) {

        //     }
        // }
        // 思路被前面幾題 hash 給限制住了歐，不見得要用這兩種方法
        // 直接 sort 子字串就能做快速對比並儲存了
        // 看來 hash 考的還有關於 hash function 的設計夠不夠靈活
        // hash key 應該要學會改用處理過後的特徵值
        unordered_map<string, vector<string>> groups;
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());  // 排序後當作唯一的 Key
            groups[key].push_back(s);      // 把原始字串塞進對應的組別
        }
    }
};
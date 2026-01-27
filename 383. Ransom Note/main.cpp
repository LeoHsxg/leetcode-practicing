#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// review: hash 的本質是以空間換時間，用 O(1) 查找索引值
// hash func => 把任何輸入（字串、數字、物件）轉換為索引
// map, set 的 stl 規則沒有不同，一樣是在 <> 宣告此容器內物品的型別
// map<int, string> 的鍵值為整數，裡面資料則是字串
// 在做 hash 時請務必用 unorder_ 版本，其底層才是 hash table O(1)
// map -> 用 find(key), set -> insert, count(key), erase
// .
// 這兩者的優勢是與一般陣列並用，作為反向儲存對應關係
// 同時其型別自訂，也同時含有稀疏陣列的優點

// 383. Ransom Note
class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        // return magazine.find(ransomNote) != string::npos;
        // 對於全小寫的英文字串時，用普通的 int dic[26] 才是最速解xd
        unordered_map<char, int> dic;
        for (char c : magazine) {
            dic[c]++;
        }
        for (char c : ransomNote) {
            // 訪問不存在的 key 時，會自動初始化其為 0
            // 對於計數 count 時很方便
            if (dic.find(c) == dic.end())
                return false;
            if (dic[c]-- <= 0)
                return false;
        }
        return true;
    }
};
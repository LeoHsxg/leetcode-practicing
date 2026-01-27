#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// 205. Isomorphic Strings
class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> dic;
        unordered_map<char, char> rev_dic;
        // 要把 s 都替換成 t
        for (int i = 0; i < s.size(); i++) {
            char charS = s[i];
            char charT = t[i];
            // 還沒被替換過，被轉換與轉換的都算
            if (dic.find(charS) == dic.end() && rev_dic.find(charT) == rev_dic.end()) {
                dic[charS] = t[i];
                rev_dic[charT] = s[i];
            } else {
                // charS 已經有值，要比對對錯
                if (dic[charS] != t[i])
                    return false;
                // 或是 charT 已經有值，也來比對對錯
                else if (rev_dic[charT] != s[i])
                    return false;
            }
        }
        return true;
    }
};

// 這題寫得有點醜，先排除非法品項就不用層層包裹了
// 後面就可以統一一起更新資料
/*
    // 如果 charS 已經被對映過，檢查對映的是不是 charT
    if (dic.count(charS) && dic[charS] != charT) return false;

    // 如果 charT 已經被對映過，檢查對映的是不是 charS
    if (rev_dic.count(charT) && rev_dic[charT] != charS) return false;

    // 建立/更新連結
    dic[charS] = charT;
    rev_dic[charT] = charS;
 */

int main() {
    Solution sol;
    string s = "egg";
    string t = "add";
    cout << sol.isIsomorphic(s, t);
}
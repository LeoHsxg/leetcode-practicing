#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 3. Longest Substring Without Repeating Characters
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        deque<char> dq;
        set<char> charSet;
        int ans = 0;

        for (char c : s) {
            if (charSet.find(c) == charSet.end()) {
                dq.push_back(c);
                charSet.insert(c);
                if (ans < dq.size())
                    ans = dq.size();
            } else if (charSet.find(c) != charSet.end()) {
                while (charSet.find(c) != charSet.end()) {
                    char tmp = dq.front();
                    charSet.erase(tmp);
                    dq.pop_front();
                }
                dq.push_back(c);
                charSet.insert(c);
                if (ans < dq.size())
                    ans = dq.size();
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s = "abcabcbb";
    cout << sol.lengthOfLongestSubstring(s);
}

/*
 1. 你其實不需要一個真實的容器來存放字元，因為原始字串 s 已經在那裡了。
    你只需要兩個整數（索引）來代表這個窗口的邊界即可。
 2. 與其用 set，不如用 int arr[128] 來記錄每個字元最後一次出現的位置。
 3. if ( > ) 可以直接用 ans = max( , ) 來寫。
*/
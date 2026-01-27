#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 71. Simplify Path
class Solution {
   public:
    string simplifyPath(string path) {
        // 用 getline 和 stringstream 會更快更優雅，但這背起來三分鐘後就忘了...
        deque<string> q;
        string tmpS;
        for (int i = 0; i < path.size(); i++) {
            char c = path[i];
            // 遇到 / 時再統一整理 tmpS 的資料
            if (c == '/') {
                if (tmpS.empty())
                    continue;
                else if (tmpS == ".") {
                    tmpS = "";
                    continue;
                } else if (tmpS == "..") {
                    if (!q.empty())
                        q.pop_back();
                    tmpS = "";
                } else {
                    q.push_back(tmpS);
                    tmpS = "";
                }
            } else {
                tmpS += c;
            }
        }
        if (!tmpS.empty()) {
            if (tmpS == "..") {
                if (!q.empty())
                    q.pop_back();
            } else if (tmpS == ".") {
                tmpS = "";
            } else
                q.push_back(tmpS);
        }

        string ans;
        // for (string p : q) { // 用 for {:} 炸 deque 其實比較方便
        while (!q.empty()) {
            tmpS = q.front();
            q.pop_front();
            ans += '/';
            ans.insert(ans.end(), tmpS.begin(), tmpS.end());
        }
        if (ans.empty())
            ans = "/";
        return ans;
    }
};

int main() {
    Solution sol;
    // string path = "/Documents/../Pictures";
    string path = "/home/user/Documents/../Pictures";
    cout << sol.simplifyPath(path);
}
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

// 290. Word Pattern
class Solution {
   public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> dic_pat;
        unordered_map<string, char> dic_str;

        stringstream ss(s);
        string tmpS;
        int i = 0;
        // while getline(ss, tmpS, ' ');
        while (ss >> tmpS) {
            // cout << tmpS << endl;
            if (i >= pattern.size())
                return false;
            if (dic_pat.count(pattern[i]) && dic_pat[pattern[i]] != tmpS)
                return false;
            if (dic_str.count(tmpS) && dic_str[tmpS] != pattern[i])
                return false;

            dic_pat[pattern[i]] = tmpS;
            dic_str[tmpS] = pattern[i];
            i++;
        }
        if (i < pattern.size())
            return false;
        return true;
    }
};
int main() {
    Solution sol;
    string s = "abba";
    string t = "dog cat cat dog";
    cout << sol.wordPattern(s, t);
}
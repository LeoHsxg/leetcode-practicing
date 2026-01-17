#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// 125. Valid Palindrome
class Solution {
   public:
    bool isPalindrome(string s) {
        int a = 0;
        int b = s.size() - 1;
        bool ans = true;
        if (s.empty())
            return true;
        while (a <= b) {
            while (a < s.size() && !isalnum(s[a])) {
                a += 1;
            }
            while (b >= 0 && !isalnum(s[b])) {
                b -= 1;
            }
            if (a > b)
                break;
            if (tolower(s[a]) != tolower(s[b]))
                return false;
            a += 1;
            b -= 1;
        }
        return true;
    }
};

int main() {
    // cout << "test";
    Solution sol;
    string s = " ";
    cout << sol.isPalindrome(s);
}
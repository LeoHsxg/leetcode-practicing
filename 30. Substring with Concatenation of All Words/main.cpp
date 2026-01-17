#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLen = words[0].size();
        int wordCnt = words.size();
        int winlen = wordLen * wordCnt;

        vector<int> visitedWords(wordCnt, 0);
        vector<vector<size_t>> positions(wordCnt, vector<size_t>(0, 10005));
        // review: vector<t>(size, init) 別順序搞混了...

        for (int i = 0; i < wordCnt; i++) {
            size_t pos = s.find(words[i]);
            int point = 0;
            while (pos != string::npos) {
                positions[i][point++] = pos;
                pos = s.find(words[i], pos + 1);
            }
        }
    }
};

// 邏輯問題：如果 words 是 ["foo", "foo"]，程式可能會炸
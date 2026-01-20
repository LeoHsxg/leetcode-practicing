#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 211. Design Add and Search Words Data Structure
class TrieNode {
   public:
    TrieNode* children[26];  // only lowercase
    bool isEndOfWord;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

// At most 10^4 calls will be made to addWord and search.
// 但也不需要刪除，所以也不用啥特別優化，只要查詢夠快就可以了
class WordDictionary {
   public:
    TrieNode* root;

    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int index = c - 'a';
            if (cur->children[index] == nullptr) {
                cur->children[index] = new TrieNode;
            }
            cur = cur->children[index];
        }
        cur->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* cur = root;
        return searchdfs(cur, 0, word);
    }

    bool searchdfs(TrieNode* cur, int t, const string& word) {
        // 特殊符號匹配
        if (word[t] == '.') {
            // word 比單字還長的字尾情形未排除
            if (t == word.size() - 1) {
                for (int i = 0; i < 26; i++) {
                    if (cur->children[i] != nullptr && cur->children[i]->isEndOfWord)
                        return true;
                }
                return false;
            }
            for (int i = 0; i < 26; i++) {
                // cout << "now is " << (char)('a' + i) << endl;
                if (cur->children[i] == nullptr) {
                    // cout << "skip" << endl; // a, n 有成功進去
                    continue;
                }
                if (searchdfs(cur->children[i], t + 1, word))
                    return true;
            }
            return false;
        }

        int index = word[t] - 'a';
        // 遞迴邊界
        if (t == word.size() - 1) {
            if (cur->children[index] && cur->children[index]->isEndOfWord)
                return true;
            return false;
        }
        // 遞迴 & 回傳結果
        if (cur->children[index] == nullptr) {
            return false;
        }
        return searchdfs(cur->children[index], t + 1, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("at");
    wordDictionary.addWord("and");
    wordDictionary.addWord("bat");
    cout << wordDictionary.search(".at") << endl;  // return True
    // cout << wordDictionary.search("pad") << endl;  // return False
    // cout << wordDictionary.search(".ad") << endl;  // return True
    // cout << wordDictionary.search("b..") << endl;  // return True
}
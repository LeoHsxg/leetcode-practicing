#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 208. Implement Trie (Prefix Tree)
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

class Trie {
   public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(string word) {
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
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (i == word.size() - 1) {
                if (cur->children[index] && cur->children[index]->isEndOfWord)
                    return true;
            }
            if (cur->children[index] == nullptr) {
                return false;
            }
            cur = cur->children[index];
        }
        // 因為會有字一半的情況，所以不能預設 true
        return false;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (cur->children[index] == nullptr) {
                return false;
            }
            cur = cur->children[index];
        }
        // 只問前綴，預設 true
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;    // return True
    cout << trie.search("app") << endl;      // return False
    cout << trie.startsWith("app") << endl;  // return True
    trie.insert("app");
    cout << trie.search("app") << endl;  // return True
}
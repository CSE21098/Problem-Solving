#include <bits/stdc++.h>
using namespace std;

// Trie implementation
class Trie {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEndOfWord;
    };

    TrieNode* root;

    TrieNode* createNode() {
        return new TrieNode();
    }

public:
    Trie() {
        root = createNode();
    }

    void insert(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = createNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

    void suggestions(const string& prefix) {
        TrieNode* current = root;
        vector<string> suggestions;
        for (char c : prefix) {
            if (current->children.find(c) == current->children.end()) {
                cout << "No string found with this prefix\n";
                return;
            }
            current = current->children[c];
        }
        getSuggestions(current, prefix);
    }

    void getSuggestions(TrieNode* node, string prefix) {
        if (node->isEndOfWord) {
            cout << prefix << endl;
        }
        for (auto& child : node->children) {
            getSuggestions(child.second, prefix + child.first);
        }
    }
};

int main() {
    Trie trie;
    trie.insert("hello");
    trie.insert("dog");
    trie.insert("hell");
    trie.insert("cat");
    trie.insert("a");
    trie.insert("hel");
    trie.insert("help");
    trie.insert("helps");
    trie.insert("helping");

    trie.suggestions("hel");

    return 0;
}
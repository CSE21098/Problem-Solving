class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    unordered_map<string, int> wordFrequencies;
};

class AutoCompleteSystem {
private:
    TrieNode* root;
    TrieNode* currentNode;
    string currentQuery;

    static bool compareFrequencies(pair<string, int>& a, pair<string, int>& b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    }

public:
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        currentNode = root;
        currentQuery = "";

        for (int i = 0; i < sentences.size(); ++i) {
            insertSentence(sentences[i], times[i]);
        }
    }

    void insertSentence(string sentence, int time) {
        TrieNode* node = root;
        for (char c : sentence) {
            if (!node->children[c]) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->wordFrequencies[sentence] += time;
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            insertSentence(currentQuery, 1);
            currentQuery = "";
            currentNode = root;
            return {};
        }

        currentQuery += c;
        if (!currentNode->children[c]) {
            currentNode->children[c] = new TrieNode();
            currentNode = currentNode->children[c];
            return {};
        }

        currentNode = currentNode->children[c];
        vector<pair<string, int>> suggestions(currentNode->wordFrequencies.begin(), currentNode->wordFrequencies.end());
        sort(suggestions.begin(), suggestions.end(), compareFrequencies);

        vector<string> result;
        for (int i = 0; i < min(3, (int)suggestions.size()); ++i) {
            result.push_back(suggestions[i].first);
        }

        return result;
    }
};

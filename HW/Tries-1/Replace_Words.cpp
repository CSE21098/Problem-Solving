class Node{
    public: 
    vector<Node*> childs;
    bool isEnd;
    Node(){
        childs = vector<Node*>(26, nullptr);
        isEnd = false;
    }
};
class Solution {
public:
    Node* root;
    Solution(){
        root = new Node();
    }
    vector<string> splitString(string str, char delim){
        string subStr = "";
        vector<string> res;
        for(auto &ch : str){
            if(ch != delim){
                subStr.push_back(ch);
            }
            else{
                res.push_back(subStr);
                subStr = "";
            }
        }
        res.push_back(subStr);
        return res;
    }
    void insert(Node* root, string &str){
        Node* curr = root;
        for(auto &ch : str){
            int idx = ch - 'a';
            if(curr->childs[idx] == nullptr){
                Node* newNode = new Node();
                curr->childs[idx] = newNode;
            }
            curr = curr->childs[idx];
        }
        curr->isEnd = true;
    }
    bool searchPrefix(Node* root, string &str, int idx, string &asf){
        if(idx == str.length()){
            return false;
        }
        if(root->isEnd){
            return true;
        }
        char ch = str[idx];
        if(root->childs[ch - 'a'] == nullptr){
            return false;
        }
        else{
            asf.push_back(ch);
            bool val = searchPrefix(root->childs[ch - 'a'], str, idx + 1, asf);
            if(val){
                return true;
            }
            asf.pop_back();
        }
        return false;
    }
    string replaceWords(vector<string>& roots, string sentence) {
        for(auto &rootWord : roots){
            insert(root, rootWord);
        }
        vector<string> words = splitString(sentence, ' ');
        string res;
        for(auto &word : words){
            string asf = "";
            bool val = searchPrefix(root, word, 0, asf);
            if(val){
                res += asf;
            }else{
                res += word;
            }

            res.push_back(' ');
        }
        res.pop_back();
        return res;
    }
};
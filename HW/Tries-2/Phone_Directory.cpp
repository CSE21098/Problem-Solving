class TrieNode{
    public:
        char data;
        TrieNode *children[26];
        bool isTerminal;
    TrieNode(char ch){
        data= ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public: 
    TrieNode* root;
    Trie(){
        root =  new TrieNode('\0');
    }
    void insertutil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true; 
            return ;
        }
        int index= word[0] - 'a';
        TrieNode* child;

        if(root->children[index]){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertutil(child,word.substr(1));
    }
    void insertword(string word){
        insertutil(root,word);
    }
    void print(TrieNode* curr,vector<string> &temp, string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        for(char ch= 'a'; ch<='z';ch++){
            TrieNode* next= curr->children[ch-'a'];
            if(next!=NULL){
                prefix.push_back(ch);
                print(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }
    
    vector<vector<string>> getsuggestions(string s){
        TrieNode* prev= root;
        vector<vector<string>> output;
        string prefix= "";
        int i=0;
        for(i=0;i<s.length();i++){
            char last =  s[i];
            prefix.push_back(last);
    
            TrieNode * curr=prev->children[last-'a'];
            if(curr==NULL){
                break;
            }
            vector<string> temp;
            print(curr,temp,prefix);
            output.push_back(temp);
            temp.clear();
            prev=curr;
        }
        if( i < s.size()){

                while( i < s.size()){

                    output.push_back({"0"});

                    i++;

                }
        }
        return output;
    }

};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie * t= new Trie();
        
        for(int i=0;i<n;i++){
            string str =  contact[i];
            t->insertword(str);
        }
        return t->getsuggestions(s);
    }
};
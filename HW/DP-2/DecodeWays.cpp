class Solution {
private:
    int solve(string &s, int ind, map<string, char> &m) {
        if(s[ind] == '0') 
            return 0;
        if(ind == s.length()-1) 
            return 1;
        if(ind == s.length()) 
            return 1;
        int takeOne = solve(s, ind+1, m);
        int takeTwo = 0;
        string str = "";
        str.push_back(s[ind]);
        str.push_back(s[ind+1]);
        if(m.find(str) != m.end()) 
            takeTwo = solve(s, ind+2, m);
        return takeOne + takeTwo;
    }

    int solveMem(string &s, int ind, map<string, char> &m, vector<int> &dp) {
        if(s[ind] == '0')
            return 0;
        if(ind == s.length()-1) 
            return 1;
        if(ind == s.length()) 
            return 1;
        if(dp[ind] != -1) 
            return dp[ind];
        int takeOne = solveMem(s, ind+1, m, dp);
        int takeTwo = 0;
        string str = "";
        str.push_back(s[ind]);
        str.push_back(s[ind+1]);
        if(m.find(str) != m.end()) 
            takeTwo = solveMem(s, ind+2, m, dp);
        return dp[ind] = takeOne + takeTwo;
    }

    int solveTab(string &s, map<string, char> &m) {
        vector<int> dp(s.length()+1, 0);
        if(s[s.length()-1] != '0') dp[s.length()-1] = 1;
        dp[s.length()] = 1;
        for(int i = s.length()-2; i >= 0; i--) {
            if(s[i] != '0') {
                int takingOne = dp[i+1];
                int takingTwo = 0;
                string str = "";
                str.push_back(s[i]);
                str.push_back(s[i+1]);
                if(m.find(str) != m.end()) takingTwo = dp[i+2];
                dp[i] = takingOne + takingTwo; 
            }
        }
        return dp[0];
    }

    int solveSO(string &s, map<string, char> &m) {
        int next = 0;
        if(s[s.length()-1] != '0' && s[0] != '0') next = 1;
        int nextAfterOne = 1;

        for(int i = s.length()-2; i >= 0; i--){
            if(s[i] != '0'){
                int takingOne = next;
                int takingTwo = 0;
                string str = "";
                str.push_back(s[i]);
                str.push_back(s[i+1]);
                if(m.find(str) != m.end()) takingTwo = nextAfterOne;
                int curr = takingOne + takingTwo; 
                nextAfterOne = next;
                next = curr;
            }
            else{
                nextAfterOne = next;
                next = 0;
            }
        }
        return next;
    }

public:
    int numDecodings(string s){
        int ind = 0;
        map<string, char> m;

        for(int i = 0; i < 26; i++){
            string str = to_string(i+1);
            m[str] = 'A'+i;
        }
        // return solve(s, ind, m);
        // vector<int> dp(s.length()+1, -1);
        // return solveMem(s, ind, m, dp);
        // return solveTab(s, m);
        return solveSO(s, m);
    }
};

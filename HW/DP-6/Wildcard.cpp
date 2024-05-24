class Solution {
public:
    int solve(string str,string pattern,int i,int j){
        if(i<0 && j<0){
            return 1;
        }
        if(i>=0 && j<0){
            return 0;
        }
        if(j>=0 && i<0){
            for(int k=0;k<=j;k++){
                if(pattern[k]!='*'){
                    return 0;
                }
            }
            return 1;
        }
        if(str[i]==pattern[j] || pattern[j]=='?'){
            return solve(str,pattern,i-1,j-1);
        }
        else if(pattern[j]=='*'){
            return (solve(str,pattern,i-1,j) || solve(str,pattern,i,j-1));
        }
        else{
            return 0;
        }
    }
    int solveMem(string &str,string &pattern,int i,int j,vector<vector<int>> &dp){
        if(i<0 && j<0){
            return 1;
        }
        if(i>=0 && j<0){
            return 0;
        }
        if(j>=0 && i<0){
            for(int k=0;k<=j;k++){
                if(pattern[k]!='*'){
                    return 0;
                }
            }
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(str[i]==pattern[j] || pattern[j]=='?'){
            return dp[i][j] = solveMem(str,pattern,i-1,j-1,dp);
        }
        else if(pattern[j]=='*'){
            return dp[i][j] = (solveMem(str,pattern,i-1,j,dp) || solveMem(str,pattern,i,j-1,dp));
        }
        else{
            return dp[i][j] = 0;
        }
    }
    int solveTab(string &s,string &p){
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,0));
        dp[0][0] =1;
        for(int j=1;j<=p.size();j++){
            bool flag =true;
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=p.size();j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[s.size()][p.size()];
    }
    int solveSO(string &s,string &p){
        vector<int> curr(p.size()+1,0);
        vector<int> next(p.size()+1,0);
        curr[0] =1;
        for(int j=1;j<=p.size();j++){
            bool flag =true;
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    flag = false;
                    break;
                }
            }
            curr[j] = flag;
        }
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=p.size();j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    next[j] = curr[j-1];
                }
                else if(p[j-1]=='*'){
                    next[j] = (curr[j] || next[j-1]);
                }
                else{
                    next[j] = 0;
                }
            }
            curr=next;
        }
        return curr[p.size()];
    }
    bool isMatch(string s, string p) {
        // return solve(s,p,s.size()-1,p.size()-1);
        // vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
        // return solveMem(s,p,s.size()-1,p.size()-1,dp);
        // return solveTab(s,p);
        return solveSO(s,p);
    }
};
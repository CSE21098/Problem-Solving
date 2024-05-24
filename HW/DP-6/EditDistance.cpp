class Solution {
public:
    int solve(string a,string b,int i,int j){
        if(i==a.size()){
            return b.size()-j;
        }
        if(j==b.size()){
            return a.size()-i;
        }
        if(a[i]==b[j]){
            return solve(a,b,i+1,j+1);
        }
        else{
            int insert =1 + solve(a,b,i,j+1);
            int del =1 + solve(a,b,i+1,j);
            int rep =1 + solve(a,b,i+1,j+1);
            return min(insert,min(del,rep));
        }
    }
    int solveMem(string a,string b,int i,int j,vector<vector<int>> &dp){
        if(i==a.size()){
            return b.size()-j;
        }
        if(j==b.size()){
            return a.size()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(a[i]==b[j]){
            return solveMem(a,b,i+1,j+1,dp);
        }
        else{
            int insert = 1 + solveMem(a,b,i,j+1,dp);
            int del = 1 + solveMem(a,b,i+1,j,dp);
            int rep = 1 + solveMem(a,b,i+1,j+1,dp);
            return dp[i][j] = min(insert,min(del,rep));
        }
    }
    int solvetab(string a,string b){
        vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0));
        for(int j=0;j<b.size();j++){
            dp[a.size()][j] = b.size()-j;
        }
        for(int j=0;j<a.size();j++){
            dp[j][b.size()] = a.size()-j;
        }
        for(int i=a.size()-1;i>=0;i--){
            for(int j= b.size()-1;j>=0;j--){
                if(a[i]==b[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    int insert =1 + dp[i][j+1];
                    int del =1 + dp[i+1][j];
                    int rep =1 + dp[i+1][j+1];
                    dp[i][j] = min(insert,min(del,rep));
                }
            }
        }
        return dp[0][0];
    }
    int solveSO(string a,string b){
        vector<int> curr(b.size()+1,0);
        vector<int> next(b.size()+1,0);
        for(int j=0;j<b.size();j++){
            next[j] = b.size()-j;
        }

        for(int i=a.size()-1;i>=0;i--){
            for(int j= b.size()-1;j>=0;j--){
                curr[b.size()] = a.size()-i;
                if(a[i]==b[j]){
                    curr[j] = next[j+1];
                }
                else{
                    int insert = 1 + curr[j+1];
                    int del = 1 + next[j];
                    int rep = 1 + next[j+1];
                    curr[j] = min(insert,min(del,rep));
                }
            }
            next = curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {
        // return solve(word1,word2,0,0);
        // vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        // return solveMem(word1,word2,0,0,dp);
        if(word1.size()==0){
            return word2.size();
        }
        if(word2.size()==0){
            return word1.size();
        }
        return solveSO(word1,word2);
    }
};
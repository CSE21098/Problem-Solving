class Solution {
public:
    long long fun(int ind,int n,vector<vector<int>>& question,vector<long long>&dp){
            if(ind>=n) 
                return 0;
            if(dp[ind]!=-1) 
                return dp[ind];
            long long take=0,nottake=0;
            take=question[ind][0]+fun(ind+question[ind][1]+1,n,question,dp);
            nottake=fun(ind+1,n,question,dp);
            return dp[ind]=max(take,nottake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n+1,-1);
        return fun(0,n,questions,dp);
    }
};
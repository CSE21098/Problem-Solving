class Solution {
public:
    long long solveMem(int ind,vector<vector<int>>& questions,vector<long long>&dp){
        if(ind>=questions.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        long long notTake=solveMem(ind+1,questions,dp);
        long long take=questions[ind][0]+solveMem(ind+questions[ind][1]+1,questions,dp);
        return dp[ind]=max(take,notTake);
    }
    long long solveTab(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            int jump = min(n, ind+questions[ind][1]+1);
            long long notTake=dp[ind+1];
            long long take=questions[ind][0]+dp[jump];
            dp[ind]=max(notTake,take);
        }
        return dp[0];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        // vector<long long>dp(questions.size()+1,-1);
        // return solveMem(0,questions,dp);
        return solveTab(questions);
    }
};

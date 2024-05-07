class Solution {
public:
    int solve(int n){
        if (n == 1 or n == 2)
            return n;
        return solve(n - 1) + solve(n - 2);
    }
    int solveMem(int n,vector<int> &dp){
        if (n == 1 or n == 2)
            return n;
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n] = solveMem(n - 1,dp) + solveMem(n - 2,dp);
    }
    int solveTab(int n){
        if (n == 1 or n == 2)
		return n;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
    int solveSO(int n){
        if (n == 0 || n == 1) {
            return 1;
        }
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
    int climbStairs(int n) {
        // return solve(n);
        // vector<int> dp(n + 1, -1);
	    // return solveMem(n, dp);
        // return solveTab(n);
        return solveSO(n);
    }
};

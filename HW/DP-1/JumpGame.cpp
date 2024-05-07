class Solution {
public:
    int solve(int i, int n, vector<int>& nums) {
        if(i == n-1) 
            return 0;
        int mini = 1e8;
        for(int j = i+1; (j <= i+nums[i] and j < n); j++) {
            mini = min(mini, 1+solve(j, n, nums));
        }
        return mini;
    }
    int solveMem(int i, int n, vector<int>& nums, vector<int> &dp) {
        if(i == n-1) 
            return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int mini = 1e8;
        for(int j = i+1; (j <= i+nums[i] and j < n); j++) {
            mini = min(mini, 1+solveMem(j, n, nums,dp));
        }
        return dp[i] = mini;
    }
    
    int solveTab(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        for(int i = n-1; i >= 0; i--) {
            if(i == n-1) 
                dp[i] = 0;
            else {
                int minSteps = 1e8;
                for(int j = i+1; (j <= i+nums[i] and j < n); j++) {
                    minSteps = min(minSteps, 1+dp[j]);
                }
                dp[i] = minSteps;
            }
        }
        return dp[0];
    }
    int jump(vector<int>& nums) {
        // return solve(0, nums.size(), nums);
        // vector<int> dp(nums.size(), -1);
        // return solve(0, nums.size(), nums,dp);
        return solveTab(nums);

    }
};

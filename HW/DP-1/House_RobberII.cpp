class Solution {
public:
    int help1(vector<int>nums,vector<int>&dp,int i){
        if(i>=nums.size()-1){
            return 0;
        }
        if(dp[i]!=-1) 
            return dp[i];
        int take=nums[i]+help1(nums,dp,i+2);
        int notTake=0+help1(nums,dp,i+1);
        dp[i]=max(take,notTake);
        return dp[i];
    }
    int help2(vector<int>nums,vector<int>&dp,int i){
        if(i<=0){
            return 0;
        }
        if(dp[i]!=-1)  
            return dp[i];
        int take=nums[i]+help2(nums,dp,i-2);
        int notTake=0+help2(nums,dp,i-1);
        dp[i]=max(take,notTake);
        return dp[i];
    }
    int solveTab(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);
        dp1[0] = nums[0];
        for (int i = 1; i < nums.size() - 1; i++) {
            int take = nums[i] + ((i > 1) ? dp1[i - 2] : 0);
            int notTake = 0 + dp1[i - 1];
            dp1[i] = max(take, notTake);
        }
        dp2[0] = nums[0];
        dp2[1] = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            int take = nums[i] + ((i - 2 == 0) ? 0 : dp2[i - 2]);
            int notTake = 0 + dp2[i - 1];
            dp2[i] = max(take, notTake);
        }
        int ans1 = dp1[nums.size() - 2];
        int ans2 = dp2[nums.size() - 1];
        return max(ans1, ans2);
    }

    int rob(vector<int>& nums) {
        // if(nums.size()==1) 
        //     return nums[0];
        // vector<int>dp(nums.size(),-1);
        // int ans1=help1(nums,dp,0);
        // vector<int>dp1(nums.size(),-1);
        // int ans2=help2(nums,dp1,nums.size()-1);
        // return max(ans1,ans2);;
        return solveTab(nums);
    }
};

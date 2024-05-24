class Solution {
public:
    int solve(vector<int> &nums,int curr,int prev){
        if(curr==nums.size()){
            return 0;
        }
        int take=0;
        int noTake = 0;
        if(prev==-1 || nums[curr]>nums[prev]){
            take = 1+solve(nums,curr+1,curr);
        }
        noTake = solve(nums,curr+1,prev);
        return max(take,noTake);
    }
    int solvemem(vector<int> &nums,int curr,int prev,vector<vector<int>> &dp){
        if(curr==nums.size()){
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int take=0;
        int noTake = 0;
        if(prev==-1 || nums[curr]>nums[prev]){
            take = 1+solvemem(nums,curr+1,curr,dp);
        }
        noTake = solvemem(nums,curr+1,prev,dp);
        return dp[curr][prev+1] = max(take,noTake);
    }

    int solvetab(vector<int>&nums){
        int n =nums.size();
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int take=0;
                int noTake = 0;
                if(prev==-1 || nums[curr]>nums[prev]){
                    take = 1+dp[curr+1][curr+1];
                }
                noTake = dp[curr+1][prev+1];
                dp[curr][prev+1] = max(take,noTake);
            }
        }
        return dp[0][0];
    }

    int solveSO(vector<int>&nums){
        int n =nums.size();
        vector<int> next(n+1,0);
        vector<int> c(n+1,0);

        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int take=0;
                int noTake = 0;
                if(prev==-1 || nums[curr]>nums[prev]){
                    take = 1+next[curr+1];
                }
                noTake = next[prev+1];
                c[prev+1] = max(take,noTake);
            }
            next=c;
        }
        return next[0];
    }

    int optimal(vector<int> & nums){
        if(nums.size()==0){
            return 0;
        }
        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        // return solvemem(nums,0,-1,dp);
        // return solvetab(nums);
        // return solveSO(nums);
        return optimal(nums);
    }
};
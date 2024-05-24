class Solution {
public:
    pair<int,int> helperMem(vector<int>& nums, int pos, vector<pair<int,int>>& dp){
        int v = 0, c = 1; 
        for(int i=pos+1; i<nums.size(); i++){
            if(nums[pos] < nums[i]){
                if(dp[i].first == -1) 
                    dp[i] = helperMem(nums, i, dp); 
                pair<int,int> p = dp[i]; 
                if(p.first > v) {
                    v = p.first;
                    c = 0;
                    c+= p.second;  
                }
                else if(p.first == v){
                    c += p.second; 
                }
            }
        }
        return {v+1, c}; 
    }
    int solveMem(vector<int>& nums){
        int v = 0, c = 0; 
        vector<pair<int,int>> dp(nums.size()+1, {-1, -1}); 
        for(int i=0; i<nums.size(); i++){
            if(dp[i].first == -1) 
                dp[i] = helperMem(nums, i, dp); 
            pair<int,int> p = dp[i]; 
            if(p.first > v){ 
                v = p.first; 
                c = p.second; 
            }
            else if(p.first == v){
                c += p.second;
            }
        }
        return c;
    }
    int solveTab(vector<int>& nums) {
        vector<pair<int,int>> dp(nums.size(), {-1,-1}); 
        dp[nums.size()-1] = {1,1}; 
        for(int i=nums.size()-2; i>=0; i--){
            int v = 0, c = 1; 
            for(int j=i+1; j<nums.size(); j++){
                if(nums[j] <= nums[i]) continue; 
                if(dp[j].first > v){
                    v = dp[j].first; c = dp[j].second; 
                }
                else if(dp[j].first == v){
                    c += dp[j].second; 
                }
            }
            dp[i] = {v+1, c}; 
        }

        sort(dp.begin(), dp.end()); 
        int v = dp[dp.size()-1].first; int c = 0; 
        for(int i=dp.size()-1; i>=0; i--) if(dp[i].first == v) c += dp[i].second; else break; 

        return c;
    }
    int findNumberOfLIS(vector<int>& nums) {
        // return solveMem(nums);
        return solveTab(nums);
    }

};
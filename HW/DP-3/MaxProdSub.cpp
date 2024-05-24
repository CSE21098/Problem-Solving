class Solution {
public:
    int dfs(int i, vector<int>& nums) {
        if (i >= nums.size() - 1) return nums[nums.size() - 1];
        
        int res = dfs(i + 1, nums);
        int maxVal = INT_MIN;
        int product = 1;
        
        for (int j = i; j < nums.size(); j++) {
            product *= nums[j];
            maxVal = max(maxVal, product);
        } 
        return max(res, maxVal);
    }
    int solve(vector<int>& nums) {
        int maxVal = 1, minVal = 1;
        if (nums[nums.size() - 1] != 0) {
            maxVal = nums[nums.size() - 1];
            minVal = maxVal;
        }
        int res = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] == 0) {
                minVal = 1;
                maxVal = 1;
                res = res > 0 ? res : 0;
                continue;
            }
            int temp = maxVal;
            maxVal = max(maxVal * nums[i], minVal * nums[i]);
            maxVal = max(maxVal, nums[i]);
            minVal = min(temp * nums[i], minVal * nums[i]);
            minVal = min(minVal, nums[i]);
            res = max(res, maxVal);
        }
        return res;
    }
    int solveTab(vector<int>& nums) {
        int maxProd = 1, minProd = 1;
        vector<int> dp(nums.size());
        
        if (nums[nums.size() - 1] == 0) {
            dp[nums.size() - 1] = 0;
        }
        else{
            dp[nums.size() - 1] = nums[nums.size() - 1];
            maxProd = nums[nums.size() - 1];
            minProd = maxProd;
        }
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            int res = dp[i + 1];
            if (nums[i] == 0) {
                minProd = 1;
                maxProd = 1;
                dp[i] = res > 0 ? res : 0;
                continue;
            }    
            int temp = maxProd;
            maxProd = max({maxProd * nums[i], minProd * nums[i], nums[i]});
            minProd = min({temp * nums[i], minProd * nums[i], nums[i]});
            
            res = max(res, maxProd);
            dp[i] = res;
        }   
        return dp[0];
    }
    int solveSO(vector<int>& nums) {
        int maxProd = 1, minProd = 1;
        if (nums[nums.size() - 1] != 0) {
            maxProd = nums[nums.size() - 1];
            minProd = maxProd;
        }
        int res = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] == 0) {
                minProd = 1;
                maxProd = 1;
                res = res > 0 ? res : 0;
                continue;
            }
            int temp = maxProd;
            maxProd = max({maxProd * nums[i], minProd * nums[i], nums[i]});
            minProd = min({temp * nums[i], minProd * nums[i], nums[i]});
            res = max(res, maxProd);
        }     
        return res;
    }
    int maxProduct(vector<int>& nums) {
        // return dfs(0, nums);
        // return solve(nums);
        // return solveTab(nums);
        return solveSO(nums);

    }
};
class Solution {
public:
    int solve(int start, int op, vector<int> &nums, vector<int> &multipliers){
        if(op == multipliers.size()) 
            return 0;
        int s1 = nums[start]*multipliers[op] + solve(start + 1, op + 1, nums, multipliers);
        int s2 = nums[nums.size() - 1 - (op - start)]*multipliers[op] + solve(start, op+1, nums, multipliers);
        
        return max(s1, s2);
    }
    int solveMem(int start, int op, vector<int> &nums, vector<int> &multipliers, vector<vector<int>> &dp){
        if(op == multipliers.size()) 
            return 0;
        if(dp[start][op] != -1) 
            return dp[start][op];
        int s1 = nums[start]*multipliers[op] + solveMem(start + 1, op + 1, nums, multipliers, dp);
        int s2 = nums[nums.size() - 1 - (op - start)]*multipliers[op] + solveMem(start, op+1, nums, multipliers, dp);
        
        return dp[start][op] = max(s1, s2);
    }
    int solveTab(vector<int> &nums, vector<int> &multipliers){
            int m = multipliers.size();
            int n = nums.size();
            vector<vector<int>> dp(m + 1, vector<int>(m + 1));
            for (int i = 0; i < m + 1; i++){
                dp[m][i] = 0;
            }
            for (int i = m - 1; i >= 0; i--){
                for (int j = i; j >= 0; j--){
                    int first = nums[j] * multipliers[i] + dp[i + 1][j + 1];
                    int last = nums[n - 1 - (i - j)] * multipliers[i] + dp[i + 1][j];
                    dp[i][j] = max(first, last);
                }
            }
            return dp[0][0];
    }
    int solveSO(vector<int>& nums, vector<int>& multi) {
		int n=nums.size();
		int m=multi.size();
		vector<int> prev(m+1,0),curr(m+1,0); 
		for(int i=m-1;i>=0;i--){
			for(int s=0;s<=i;s++){
				int front=multi[i]*nums[s]+prev[s+1];
				int back=multi[i]*nums[(n-1)-(i-s)]+prev[s];
				curr[s]=max(front,back);
			}
			prev=curr;
		}
		return curr[0];
	}
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // return solve(0, 0, nums, multipliers);
        // vector<vector<int>> dp(nums.size()+1, vector<int> (multipliers.size()+1, -1));
        // return solve(0, 0, nums, multipliers, dp);
        // return solveTab(nums, multipliers);
        return solveSO(nums, multipliers);
    }
};
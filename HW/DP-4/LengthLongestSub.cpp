class Solution {
public:

    int solve(vector<int>& nums, int N, int index, int target) {
        if (index == N)
            return (target == 0) ? 0 : INT_MIN;
        if (target == 0)
            return 0;
        int currSkip = solve(nums, N, index + 1, target);
        int currTake = INT_MIN;
        if (nums[index] <= target) {
            currTake = solve(nums, N, index + 1, target - nums[index]);
            currTake = (currTake != INT_MIN) ? 1 + currTake : currTake;
        }
        return max(currTake, currSkip);
    }
    int solveMem(vector<vector<int>>& memory, vector<int>& nums, int N, int index, int target) {
        if (target == 0)
            return 0;
        if (index == N)
            return (target == 0) ? 0 : INT_MIN;
        if (memory[index][target] != -1)
            return memory[index][target];
        int currSkip = solveMem(memory, nums, N, index + 1, target);
        int currTake = INT_MIN;
        if (nums[index] <= target) {
            currTake = solveMem(memory, nums, N, index + 1, target - nums[index]);
            currTake = (currTake != INT_MIN) ? 1 + currTake : currTake;
        }
        return memory[index][target] = max(currTake, currSkip);
    }
    int solveTab(vector<int>& nums, int target) {
        int N = nums.size();
        vector<vector<int>> dp(N + 1, vector<int>(target + 1, INT_MIN));
        dp[0][0] = 0;
        for(int index = 1; index <= N; ++index) {
            for(int currTarget = 0; currTarget <= target; ++currTarget) {
                int currSkip = dp[index - 1][currTarget];
                int currTake = INT_MIN;
                if(nums[index - 1] <= currTarget) {
                    currTake = dp[index - 1][currTarget - nums[index - 1]];
                    currTake = (currTake != INT_MIN) ? 1 + currTake : currTake;
                }
                dp[index][currTarget] = max(currTake, currSkip);
            }
        }
        return (dp[N][target] == INT_MIN) ? -1 : dp[N][target];
    }
    int solveSO(vector<int>& nums, int target) {
        int N = nums.size();
        vector<int> prevRow(target + 1, INT_MIN), currRow(target + 1, INT_MIN);
        prevRow[0] = 0;
        for(int index = 1; index <= N; ++index) {
            for(int currTarget = 0; currTarget <= target; ++currTarget) {
                int currSkip = prevRow[currTarget];
                int currTake = INT_MIN;
                if(nums[index - 1] <= currTarget) {
                    currTake = prevRow[currTarget - nums[index - 1]];
                    currTake = (currTake != INT_MIN) ? 1 + currTake : currTake;
                }
                currRow[currTarget] = max(currTake, currSkip);
            }
            prevRow = currRow;
        }
        return (prevRow[target] == INT_MIN) ? -1 : prevRow[target];
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        // int N = nums.size();
        // vector<vector<int>> memory(N, vector<int>(target + 1, -1));
        // int maxLength = solveWithMemo(memory, nums, N, 0, target);
        // return (maxLength == INT_MIN) ? -1 : maxLength;
        // return solveTab(nums,target);
        return solveSO(nums,target);

    }
};
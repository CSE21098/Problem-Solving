class Solution {
public:
	int maxi;
	int solve(vector<int> &nums, int n) {
		if (n == 1) return nums[0];
		int curr = max(nums[n - 1], solve(nums, n - 1) + nums[n - 1]);
		maxi = max(maxi, curr);
		return curr;
	}
    int solveit(vector<int> &nums) {
        int globalMaxSum = nums[0], currMaxSum = nums[0];
        for (int ind = 1; ind < nums.size(); ind++) {
            currMaxSum = max(currMaxSum + nums[ind], nums[ind]);
            globalMaxSum = max(globalMaxSum, currMaxSum);
        }
        return globalMaxSum;
    }
    int maxSubArray(vector<int> &nums) {
        // maxi = nums[0];
		// solve(nums, nums.size());
        // return maxi;
        return solveit(nums);
    }
};
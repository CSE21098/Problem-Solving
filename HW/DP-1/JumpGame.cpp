class Solution {
public:
    int jump(vector<int>& nums) {
        int N = nums.size();
        vector<int> memory(N, -1);
        return solveWithMemo(memory, nums, N, 0);
    }
    int solveWithMemo(vector<int>& memory, vector<int>& nums, int N, int index) {
        if(index == N - 1)
            return 0;
        if(index >= N)
            return INT_MAX;
        if(memory[index] != -1)
            return memory[index];
        int minJumps = INT_MAX;
        for(int jump = 1; jump <= nums[index]; ++jump) {
            int currJumps = solveWithMemo(memory, nums, N, index + jump);
            if(currJumps != INT_MAX) {
                minJumps = min(minJumps, 1 + currJumps);
            }
        }
        return memory[index] = minJumps;
    }
};
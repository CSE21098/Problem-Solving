class Solution {
public:
    int solve(vector<int>& coins, int N, int startIndex, int amount){
        if(startIndex == N)
            return (amount == 0);
        if(amount == 0)
            return 1;
        int count = 0;
        for(int index = startIndex; index < N; ++index) {
            if(coins[index] <= amount) {
                count += solve(coins, N, index, amount - coins[index]);
            }
        }
        return count;
    }
    int solveMem(vector<vector<int>>& dp, vector<int>& coins, int N, int startIndex, int amount) {
        if(startIndex == N)
            return (amount == 0);
        if(amount == 0)
            return 1;
        if(dp[startIndex][amount] != -1)
            return dp[startIndex][amount];
        int count = 0;
        for(int index = startIndex; index < N; ++index) {
            if(coins[index] <= amount) {
                count += solveMem(dp, coins, N, index, amount - coins[index]);
            }
        }
        return dp[startIndex][amount] = count;
    }
    int solveTab(int amount, vector<int>& coins) {
        int N = coins.size();
        vector<vector<int>> dp(N + 1, vector<int>(amount + 1, 0));
        dp[0][0] = 1;
        for(int index = 1; index <= N; ++index) {
            for(int currAmount = 0; currAmount <= amount; ++currAmount) {
                int currSkip = dp[index - 1][currAmount];
                int currTake = 0;
                if(coins[index - 1] <= currAmount) {
                    currTake = dp[index][currAmount - coins[index - 1]];
                }
                dp[index][currAmount] = currTake + currSkip;
            }
        }
        return dp[N][amount];
    }
    int solveSO(int amount, vector<int>& coins) {
        int N = coins.size();
        vector<int> prevRow(amount + 1, 0), currRow(amount + 1, 0);
        prevRow[0] = 1;
        for(int index = 1; index <= N; ++index) {
            for(int currAmount = 0; currAmount <= amount; ++currAmount) {
                int currSkip = prevRow[currAmount];
                int currTake = 0;
                if(coins[index - 1] <= currAmount) {
                    currTake = currRow[currAmount - coins[index - 1]];
                }
                currRow[currAmount] = currTake + currSkip;
            }
            prevRow = currRow;
        }
        return prevRow[amount];
    }
    int change(int amount, vector<int>& coins) {
        // int N = coins.size();
        // return solve(coins, N, 0, amount);
        // vector<vector<int>> dp(N, vector<int>(amount + 1, -1));
        // return solveMem(dp, coins, N, 0, amount);
        // return solveTab(amount, coins);
        return solveSO(amount, coins);
    }
};
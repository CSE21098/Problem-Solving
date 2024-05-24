class Solution {
public:

    int solve(vector<vector<int>>& obstacleGrid, int m, int n) {
        if (m == 0 && n == 0 && obstacleGrid[m][n] == 0) 
            return 1;
        if (m < 0 || n < 0 || obstacleGrid[m][n] == 1) 
            return 0;

        return solve(obstacleGrid, m - 1, n) + solve(obstacleGrid, m, n - 1);
    }
    int solveMem(vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<int>>& dp) {
        if (m == 0 && n == 0 && obstacleGrid[m][n] == 0) 
            return 1;
        if (m < 0 || n < 0 || obstacleGrid[m][n] == 1) 
            return 0;
        if (dp[m][n] != -1) 
            return dp[m][n];
        return dp[m][n] = solveMem(obstacleGrid, m - 1, n, dp) + solveMem(obstacleGrid, m, n - 1, dp);
    }

    int solveTab(vector<vector<int>>& obstacleGrid, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (obstacleGrid[i][j] == 1) 
                    dp[i][j] = 0;
                else {
                    if (i == 0 && j == 0) dp[i][j] = 1;
                    else if (i == 0) dp[i][j] = dp[i][j - 1];
                    else if (j == 0) dp[i][j] = dp[i - 1][j];
                    else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // return solve(obstacleGrid, m - 1, n - 1);
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // return solveMem(obstacleGrid, m - 1, n - 1,dp);
        return solveTab(obstacleGrid, m, n);
    }
};
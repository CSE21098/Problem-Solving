class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j){
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }
        if(i>=grid.size() || j>=grid[0].size()){
            return INT_MAX;
        }
        int down = solve(grid,i+1,j);
        int right = solve(grid,i,j+1);

        return grid[i][j] + min(down,right);
    }
    int solveMem(vector<vector<int>>& grid,int i,int j,vector<vector<long long>> &dp){
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }
        if(i>=grid.size() || j>=grid[0].size()){
            return INT_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down = solveMem(grid,i+1,j,dp);
        int right = solveMem(grid,i,j+1,dp);

        return dp[i][j]=grid[i][j] + min(down,right);
    }
    int solveTab(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) 
                    continue;
                if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j]);
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]); 
            }
        }
        return dp[m-1][n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        // return solve(grid,0,0);
        // vector<vector<long long>> dp(grid.size(),vector<long long>(grid[0].size(),-1));
        // return solveMem(grid,0,0,dp);
        return solveTab(grid);
    }
};
class Solution {
public:
    int solve(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& cost){
        if(r >= grid.size()){
            return 1e4;
        }
        if(r == grid.size() - 1){
            return grid[r][c];
        }
        int minCost = 1e4;
        for(int i = 0; i < grid[0].size(); i++){
            minCost = min(minCost, grid[r][c] + cost[grid[r][c]][i] + solve(grid, r+1, i, cost));
        }
        return minCost;
    }
    int solveMem(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& cost,vector<vector<int>> &dp){
        if(r >= grid.size()){
            return 1e4;
        }
        if(r == grid.size() - 1){
            return grid[r][c];
        }
        if(dp[r][c] != -1) {
            return dp[r][c];
        }
        int minCost = INT_MAX;
        for(int i = 0; i < grid[0].size(); i++){
            minCost = min(minCost, grid[r][c] + cost[grid[r][c]][i] + solveMem(grid, r+1, i, cost,dp));
        }
        return dp[r][c] = minCost;
    }
    int solveTab(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < n; i++){
            dp[m - 1][i] = grid[m - 1][i];
        }
        int minAns = INT_MAX;
        for(int row = m - 2; row >= 0; row--){
            for(int col = 0; col < n; col++){
                dp[row][col] = INT_MAX;
                for(int i = 0; i < n; i++){
                    int cost = grid[row][col] + moveCost[grid[row][col]][i] + dp[row + 1][i];
                    dp[row][col] = min(dp[row][col] , cost);
                }
                if(row == 0) minAns = min(minAns , dp[row][col]);
            }
        }
        return minAns;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int minAns = INT_MAX;
        // for (int i = 0; i < grid[0].size(); i++){
        //     minAns = min(minAns, solve(grid, 0, i, moveCost));
        // }
        // vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        // for (int i = 0; i < grid[0].size(); i++){
        //     minAns = min(minAns, solveMem(grid, 0, i, moveCost,dp));
        // }
        // return minAns;
        return solveTab(grid,moveCost);
    }

};
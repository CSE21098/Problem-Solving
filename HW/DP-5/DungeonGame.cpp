class Solution {
public:
    int rec(int i,int j,int n,int m,vector<vector<int>>& arr){
        if(i >= n+1 or j >= m+1) return 1e9;
        if(i == n and j == m) 
            return arr[i][j] > 0 ? 1 : 1 - arr[i][j];

        int down = rec(i+1,j,n,m,arr);
        int right = rec(i,j+1,n,m,arr);
        int res = min(down,right)-arr[i][j];
        return res > 0 ? res : 1;
    }
    int memo(int i,int j,int n,int m,vector<vector<int>>& arr,vector<vector<int>> &dp){
        if(i >= n+1 or j >= m+1) 
            return 1e9;
        if(i == n and j == m) 
            return arr[i][j] > 0 ? 1 : 1 - arr[i][j];
        if(dp[i][j] != -1) 
            return dp[i][j];
        
        int down = memo(i+1,j,n,m,arr,dp);
        int right = memo(i,j+1,n,m,arr,dp);
        int res = min(down,right)-arr[i][j];
        return dp[i][j] = res > 0 ? res : 1;
    }
    int solveTab(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        
        for(int i=n;i>=0;i--){ 
            dp[i][m] = 1e9;
        }
        for(int j=m;j>=0;j--){
            dp[n][j] = 1e9;
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i == n-1 and j==m-1){
                    dp[i][j] = arr[i][j] > 0 ? 1 : 1 - arr[i][j];
                    continue;
                }
                int down = dp[i+1][j];
                int right = dp[i][j+1];
                int res = min(down,right) - arr[i][j];
                dp[i][j] = res > 0 ? res : 1;
            }
        }
        
        return dp[0][0];
    }
    int solveSO(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vector<int> dp(m+1,1e9),curr(m+1,0);
        curr[m] = 1e9;
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i == n-1 and j==m-1){
                    curr[j] = arr[i][j] > 0 ? 1 : 1 - arr[i][j];
                    continue;
                }
                int down = dp[j];
                int right = curr[j+1];
                int res = min(down,right) - arr[i][j];
                curr[j] = res > 0 ? res : 1;
            }
            dp = curr;
        }
        
        return dp[0];
    }
    int solveSO2(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vector<int> dp(m+1,1e9);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i == n-1 and j==m-1){
                    dp[j] = arr[i][j] > 0 ? 1 : 1 - arr[i][j];
                    continue;
                }
                int down = dp[j];
                int right = dp[j+1];
                int res = min(down,right) - arr[i][j];
                dp[j] = res > 0 ? res : 1;
            }
        }
        return dp[0];
    }
    int calculateMinimumHP(vector<vector<int>>& arr) {
        // int n = arr.size(), m = arr[0].size();
        // return pre(0,0,n-1,m-1,arr);
        // vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        // return memo(0,0,n-1,m-1,arr,dp);
        // return solveTab(arr);
        // return solveSO(arr);
        return solveSO2(arr);
    }
};

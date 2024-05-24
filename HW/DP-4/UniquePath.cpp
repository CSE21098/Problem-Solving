class Solution {
public:
    int solve(int i,int j){
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        int left = solve(i,j-1);
        int up = solve(i-1,j);
        return (left+up);
    }
    int solveMem(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int left = solveMem(i,j-1,dp);
        int up = solveMem(i-1,j,dp);
        return dp[i][j]=left+up;
    }
    int solveTab(int m, int n){
        vector<vector<int>>dp(m,vector<int>(n,1));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)
                 continue;
                else{
                    int up=0,left=0;
                    if(j>0) left=dp[i][j-1];
                    if(i>0) up=dp[i-1][j];
                    dp[i][j]= up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
    int solveSO(int m, int n){
        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0&&j==0)
                    temp[j]=1;
                else{
                    int up=0,left=0;
                    if(j>0) left=temp[j-1];
                    if(i>0) up=prev[j];
                    temp[j]= up+left;
                }
            }
            prev=temp;
        }
        return prev[n-1];
    }
    int uniquePaths(int m, int n){
        // return solve(m-1,n-1);
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return solveMem(m-1,n-1,dp);
        // return solveTab(m,n);
        return solveSO(m,n);
    }
};
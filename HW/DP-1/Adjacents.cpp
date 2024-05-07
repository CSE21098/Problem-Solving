class Solution{
public:
    int solve(int n,vector<vector<int>>&mat,int r,int c,vector<vector<int>>&dp){
        if(c>=n)
            return 0;
        if(dp[r][c]!=-1)
            return dp[r][c];
        int t1 = mat[r][c] + max(solve(n,mat,1,c+2,dp),solve(n,mat,0,c+2,dp));
            int t2=solve(n,mat,1,c+1,dp);
            int t3=solve(n,mat,0,c+1,dp);
        return dp[r][c] = max(t1,max(t2,t3));
    }
    int solveSO(int n, vector<vector<int>> mat){
        int num = 0;
        int temp = max(mat[0][0],mat[1][0]);
        if(n==1) 
            return temp;
        for(int i = 2 ; i <= n ; i++){
            int curr = max(max(mat[0][i-1],mat[1][i-1])+num,temp);
            num=s;
            temp=curr;
        }
        return s;
    }
    int maxSum(int n, vector<vector<int>> mat){
        // vector<vector<int>>dp(3,vector<int>(n+1,-1));
        // return max(solve(n,mat,0,0,dp),solve(n,mat,1,0,dp));
        return solveSO(n,mat);
    }
};

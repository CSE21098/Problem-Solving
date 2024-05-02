class Solution {
public:
    int solve(int n,int k,int target){
        if(target==0 && n==0){
            return 1;
        }
        if(target<0 || (n==0 && target!=0) || (target==0 && n!=0)){
            return 0;
        }
        int ans=0;
        for(int i=1;i<=k;i++){
            ans = (ans + solve(n-1,k,target-i))%1000000007;
        }
        return ans;
    }
    int solvemem(int n,int k,int target,vector<vector<int>>&dp){
        if(target==0 && n==0){
            return 1;
        }
        if(target<0 || (n==0 && target!=0) || (target==0 && n!=0)){
            return 0;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        int ans=0;
        for(int i=1;i<=k;i++){
            ans = (ans + solvemem(n-1,k,target-i,dp))%1000000007;
        }
        
        return dp[n][target]=ans;
    }
    int solvetab(int n,int k,int target){
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        int mod= 1e9+7;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                for(int f=1;f<=k;f++){
                    if(j-f>=0){
                        dp[i][j] += dp[i-1][j-f];
                        dp[i][j] = dp[i][j]%mod;
                    }
                }    
            }
        }
        return dp[n][target];
    }
    int solveSO(int n,int k,int target){
        vector<int>curr(target+1,0);
        vector<int>prev(target+1,0);
        prev[0]=1;
        int mod= 1e9+7;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                int ans=0;
                for(int f=1;f<=k;f++){
                    if(j-f>=0){
                        ans = (ans%mod + prev[j-f]%mod)%mod;
                    }
                }    
                curr[j] = ans%mod;
            }
            prev=curr;
        }
        return prev[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        // return solve(n,k,target);
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // return solvemem(n,k,target,dp);
        // return solvetab(n,k,target);
        return solveSO(n,k,target);
    }
};
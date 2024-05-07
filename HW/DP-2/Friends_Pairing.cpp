class Solution
{
    const int mod = 1e9+7;
private:
    int solve(int n){
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            long long ans = ((dp[i - 1] * 1LL % mod) + (((dp[i - 2] * 1LL % mod) * (i - 1)) % mod)) % mod;
            dp[i] = ans;
        }
        return dp[n];
    }
    long long  solve(int n , vector<int>& dp){ 
        
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(dp[n]!=-1)
            return dp[n];
        
        int r = solve(n-1, dp)*1%mod + ((n-1)*(solve(n-2, dp)%mod))%mod;
        return  dp[n]=r%mod;   
    }
    int solveTab(int n){ 
        vector<long long> dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n;i++){
            long a=dp[i-1]%mod;
            long b=((i-1)*(dp[i-2]%mod))%mod;
            dp[i]=(a+b)%mod;
        }
        return dp[n];
    }
    
public:
    int countFriendsPairings(int n){
        // return solve(n);
        // vector<int>dp(n+1, -1);
        // return solve(n , dp);
        return solveTab(n);
    }
};   

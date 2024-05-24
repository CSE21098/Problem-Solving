class Solution {
public:
    int slide(vector<int>& cardPoints, int k){
        int mx=0;
        int l=0,r=0,n=cardPoints.size();
        for(int i=0;i<k;i++) 
            l+=cardPoints[i];
        int i=k-1;
        int j=n-1;
        while(i>=0){
           mx=max(mx,l+r);
           l-=cardPoints[i--];
           r+=cardPoints[j--];
        }
        l=0,r=0;
        for(int i=0;i<k;i++) 
            r+=cardPoints[n-1-i];
        i=0;
        j=n-k;
        while(j<n){
           mx=max(mx,l+r);
           r-=cardPoints[j++];
           l+=cardPoints[i++];
        }
        return mx;
    }
    int solve(int i,int j,vector<int>& cardPoints,int k){
        int n=cardPoints.size();
        if(k==0)
            return 0;
        if(i>j && k>0)
            return -1e9;

        return max(cardPoints[i]+solve(i+1,j,cardPoints,k-1),
                   cardPoints[j]+solve(i,j-1,cardPoints,k-1));
    }
    int solveMem(int i,int j,vector<int>& cardPoints,int k, vector<vector<vector<int>>>&dp){
        if(k==0)
            return 0;
        if(i>j && k>0)
            return -1e9;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];

        return dp[i][j][k]=max(cardPoints[i]+solveMem(i+1,j,cardPoints,k-1,dp),
                               cardPoints[j]+solveMem(i,j-1,cardPoints,k-1,dp));
    }
    int solveTab(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int maxScore = 0;
        vector<int> front(k+1), rear(k+1);
        front[0] = rear[0] = 0;
        for(int i=0;i<k;i++){
            front[i+1] = front[i]+cardPoints[i];
            rear[i+1] = rear[i] + cardPoints[n-1-i];
        }
        for(int i=0;i<=k; i++){
            int currentScore = front[i] + rear[k-i];
            maxScore = max(maxScore, currentScore);
        }
        return maxScore;
    }
    int solveSO(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int front = 0, rear = 0;
        for(int i=0;i<k; i++)
            front += cardPoints[i];
        
        int maxScore = front, currentScore;
        for(int i=k-1; i>=0; i--){
            front -= cardPoints[i];
            rear += cardPoints[n-(k-i)];
            currentScore = front+rear;
            maxScore = max(currentScore, maxScore);
        }
        return maxScore;
    }
    int maxScore(vector<int>& cardPoints, int k) {
        // return slide(cardPoints,k);
        // int n=cardPoints.size();
        // return solve(0,n-1,cardPoints,k);
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1, -1)));
        // return solveMem(0,n-1,cardPoints,k,dp);
        return solveSO(cardPoints,k);

    }
    
};
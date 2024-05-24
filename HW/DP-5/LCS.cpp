class Solution {
    int solve(int i, int j, string &txt1, string &txt2){
        if(i < 0 || j < 0)  
            return 0;
        if(txt1[i] == txt2[j])  
            return 1 + solve(i-1, j-1, txt1, txt2);
        else
            return max( solve(i-1, j, txt1, txt2), solve(i, j-1, txt1, txt2) );
    }
    int solveMem(int i, int j, string &txt1, string &txt2, vector<vector<int>> &dp){
        if(i < 0 || j < 0)  
            return 0;
        if(dp[i][j] != -1) 
            return dp[i][j];
        if(txt1[i] == txt2[j])  
            return dp[i][j] = 1 + solveMem(i-1, j-1, txt1, txt2, dp);
        else
            return dp[i][j] = max( solveMem(i-1, j, txt1, txt2, dp), solveMem(i, j-1, txt1, txt2, dp) );
    }

    int solveTab(string text1, string text2) {
        int length1 = text1.size(), length2 = text2.size();
        vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));
        for(int i=0; i<=length1; i++)
            dp[i][0] = 0;
        for(int j=0; j<=length2; j++) 
            dp[0][j] = 0;
        for(int i=1; i<=length1; i++){
            for(int j=1; j<=length2; j++){
                if(text1[i-1] == text2[j-1])  
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }
        return dp[length1][length2];
    }
    int solveSO(string text1, string text2) {
        int length1 = text1.size(), length2 = text2.size();
        vector<int> prevRow(length2 + 1, 0), currRow(length2+1, 0);
        for(int i=1; i<=length1; i++){
            for(int j=1; j<=length2; j++){
                if(text1[i-1] == text2[j-1])
                    currRow[j] = 1 + prevRow[j-1];
                else
                    currRow[j] = max( prevRow[j], currRow[j-1] );
            }   
            prevRow = currRow;
        }
        return prevRow[length2];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        // int length1 = text1.size(), length2 = text2.size();
        // return solve(length1-1, length2-1, text1, text2);
        // vector<vector<int>> dp(length1, vector<int>(length2, -1));
        // return solve(length1-1, length2-1, text1, text2,dp);
        // return solveTab(text1, text2);
        return solveSO(text1, text2);
    }
};
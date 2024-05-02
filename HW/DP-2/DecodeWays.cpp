class Solution {
public:
    vector<int> dp;
    int sizeString;
    int dfs(int i, string s){
        if(i == sizeString)
            return 1;
        if(i > sizeString || s[i] == '0')
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int res = 0;
        res += dfs(i+1, s);
        bool check1 = (s[i] == '1') ? true : false;
        bool check2 = (s[i] == '2' && s[i+1] <= 54) ? true : false;
        if(check1 | check2)
            res += dfs(i+2, s);
        dp[i] = res;
        return res;
    }

    int numDecodings(string s) {
        sizeString = s.size();
        dp.resize(sizeString+1, -1);
        return dfs(0, s);   
    }
};
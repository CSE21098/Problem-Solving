#include <bits/stdc++.h>
using namespace std;

int solve(int N) {
    if (N == 0) {
        return 1;
    }
    int cnt = 0;
    for (int i = 1; i <= 6; i++) {
        if (N - i >= 0) {
            cnt = cnt + solve(N - i);
        }
    }
    return cnt;
}

int solveMem(int N, vector<int>&dp) {
    if (N == 0) {
        return 1;
    }
    if (dp[N] != -1) {
        return dp[N];
    }
    int cnt = 0;

    for (int i = 1; i <= 6; i++) {
        if (N - i >= 0) {
            cnt = cnt + solveMem(N - i, dp);
        }
    }
    return dp[N] = cnt;
}

int solveTab(int N) {
    vector<int> dp(N+1,-1);
    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        dp[i] = 0;
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] = dp[i] + dp[i - j];
            }
        }
    }
    return dp[N];
}

int solveSO(int N) {
    vector<int> dp(6,0);
    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        int sum = 0;

        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                sum += dp[(i - j) % 6];
            }
        }

        dp[i % 6] = sum;
    }
    return dp[N % 6];
}



int main() {
    int N ;
    cin>>N;
    // cout << solve(N);
    // vector<int> dp(N+1,-1);
    // cout<<solveMem(N,dp);
    // cout<<solveTab(N);
    cout<<solveSO(N);
    return 0;
}

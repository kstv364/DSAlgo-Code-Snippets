int longestRepeatingSubsequence(string s, int n) {
    string x = string(s);
    int dp[n + 1][n + 1];

    // variation of lcs
    // lcs + (i!=j)
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else if (s[i - 1] == x[j - 1] and i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}
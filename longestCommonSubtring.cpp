void lcsubstring(string &x, string &y, int a, int b) {
    int l = 0;
    For(i, 0, a + 1) {
        For(j, 0, b + 1) {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else if (x[i - 1] == y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > l)
                    l = dp[i][j];
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    cout << l << endl;
}
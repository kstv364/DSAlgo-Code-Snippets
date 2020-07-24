void solve(int arr[], int n, int val) {

    // ways of getting any value without coin = 0
    FOR(i, 0, val + 1) {
        dp[0][i] = 0;
    }

    // ways of getting 0 value with any coin = 1
    FOR(i, 1, n + 1) {
        dp[i][0] = 1;
    }

    FOR(i, 1, n + 1) {
        FOR(j, 1, val + 1) {
            if (arr[i - 1] <= j)
                // way of getting value j without using upto ith coin +
                // way of getting value j - ith coin value using upto ith coin
                dp[i][j] = dp[i - 1][j] + dp[i][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][val] << endl;
}
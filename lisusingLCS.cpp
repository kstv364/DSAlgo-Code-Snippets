
// Does not work if array has repeated elements

int lengthOfLIS(vector<int>& nums) {
    vector<int> a(nums);
    sort(a.begin(), a.end());
    int n = nums.size();
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == nums[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}

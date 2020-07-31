int countWays(int n)
{
  // your code here

  int dp[n + 1];
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;

  for (int i = 1; i < n; i++) {
    for (int j = i; j <= n; j++) {
      dp[j] += dp[j - i] % (1000000007);
      dp[j] = dp[j] % (1000000007);
    }
  }
  return dp[n] % (1000000007);
}
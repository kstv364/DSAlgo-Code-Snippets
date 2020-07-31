
/*
Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find the number of distinct combinations to reach the given score.
*/
ll count(ll n) {
  ll dp[n + 1];
  memset(dp, 0, sizeof(dp));
  int a[] = {3, 5, 10};

  // need to understant how it works
  // 3 , 5 is same as 5, 3
  for (int i = 0; i < 3; i++) {
    for (int j = a[i]; j <= n; j++) {
      if (j == a[i])
        dp[j] += 1;
      else
        dp[j] += dp[j - a[i]];
    }
  }
  return dp[n];
}
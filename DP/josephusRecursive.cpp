//j(1) = 1
//j(n) = (j(n-1) + k-1)%n + 1
// since indexing starts from 1
void testcase() {
	int n, k;
	cin >> n >> k;
	int dp[n + 1];
	memset(dp, -1, sizeof(dp));
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = 1 + (dp[i - 1] + k - 1) % i;
	}
	cout << dp[n] << endl;

}
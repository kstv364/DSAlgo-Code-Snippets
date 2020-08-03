
#define N 10000
int dp[N + 1];


int max3(int a, int b, int c) {
    return max(max(a, b), c);
}

int helper(int n, int x, int y, int z)
{
    int mn = min(min(x, y), z);
    if (n < 0)
        return INT_MIN;
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int res = INT_MIN;
    res = 1 + max3(helper(n - x, x, y, z),
                   helper(n - y, x, y, z),
                   helper(n - z, x, y, z));
    if (res < 0)
        return dp[n] = INT_MIN;
    return dp[n] = res;
}

int maximizeTheCuts(int n, int x, int y, int z) {
    memset(dp, -1, sizeof(dp));
    int ans = helper(n, x, y, z);
    return ans == INT_MIN ? 0 : ans;
}


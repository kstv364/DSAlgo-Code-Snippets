#include <bits/stdc++.h>
using namespace std;



int solve(int n) {
    int wt[3] = {3, 5, 10};
    int dp[4][n + 1];

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == 0) dp[i][j] = 1;

            else if (wt[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - wt[i - 1]];
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[3][n];
}

void testcase() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}
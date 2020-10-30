#include <bits/stdc++.h>
using namespace std;

#define M 101
#define N 101
#define Max(a,b,c) max(max(a,b),c)

int static dp[M][N][N];

int lcs(string &a, string &b, string &c) {
    int m = a.length(), n = b.length(), p = c.length();
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            for(int k=0;k<=p;k++){
              if (i == 0 or j == 0 or k ==0)
                dp[i][j][k] = 0;
            else if (a[i - 1] == b[j - 1] and b[j-1] == c[k-1])
                dp[i][j][k] = 1 + dp[i - 1][j - 1][k-1];
            else
                dp[i][j][k] = Max(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k-1]);  
            }
            
        }
    }
    return dp[m][n][p];
}
void solve(string &a, string &b, string &c) {
    int ans =lcs(a,b,c);
    cout << ans << endl;

}

void testcase() {
    int n = 3;
    int a[n];
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    solve(s[0], s[1], s[2]);
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}
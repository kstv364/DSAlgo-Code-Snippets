#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX

//int static dp[M][N];

// DP[j] = Min number of jumps from j to end

// Recurrence 
// DP[start] = min(DP[k]) for all k reachable from start

long long solve(int arr[], int n) {
    long long dp[n], max_reach;
    dp[n-1] = 0;
    for(int i=n-2; i>=0; i--){
        dp[i] = inf;
        max_reach = min(i + arr[i],n-1);
        for(int j = max_reach; j>i; j--){
            dp[i] = min(dp[i], 1 + dp[j]);
        }
    }
    return dp[0]>=inf?-1:dp[0];
}

void testcase() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout<<solve(a, n)<<endl;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}
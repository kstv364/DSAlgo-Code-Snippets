#include <bits/stdc++.h>
using namespace std;

#define M 101
#define N 101
int static dp[M][N];
int static bracket[M][N];


void printParenthesis(int i, int j, char &name)
{
    // If only one matrix left in current segment
    if (i == j)
    {
        cout << name++;
        return;
    }
    cout << "(";
    printParenthesis(i, bracket[i][j],
                     name);
    printParenthesis(bracket[i][j] + 1, j,
                     name);
    cout << ")";
}

int mcm(int arr[], int i, int j) {
    // if one or less element no cost
    if (i >= j) return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX;
    for (int k = i; k < j; k++) {
        int temp = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (temp < mn) {
            mn = temp;
            bracket[i][j] = k;
        }
    }
    dp[i][j] = mn;
    return mn;
}
void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    memset(bracket, -1, sizeof(bracket));
    cout << mcm(a, 1, n - 1) << endl;
    char name = 'A';
    printParenthesis(1, n - 1, name);
    cout << endl;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
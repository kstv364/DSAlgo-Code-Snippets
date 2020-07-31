/*
Given an array of integers where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.


Input:
The first line contains an integer T, depicting total number of test cases.  Then following T lines contains a number n denoting the size of the array. Next line contains the sequence of integers a1, a2, ..., an.

Output:
For every test case, print the minimum number of jumps required in a new line.

User Task:
You don't need to read input or print output. Your task is to complete the function minimumjumps() that takes the jumps array and its size as inputs and returns the answer. If you cannot reach the end then return -1.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
0 <= ai <= 106

Example:
Input:
2
11
1 3 5 8 9 2 6 7 6 8 9
6
1 4 3 2 6 7
Output:
3
2
*/

int minimumjumps(int arr[], int n) {
    int dp[n];
    dp[0] = 0;// bottom up manner
    for (int i = 1; i < n; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < i; j++) {
            // if i is reachable from j and j is reachable
            if (j + arr[j] >= i and dp[j] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[j]);
        }
    }
    return dp[n - 1] == INT_MAX ? -1 : dp[n - 1];
}
/*Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // lps is lcs of x and reverse of x
        string x = string(s);
        reverse(x.begin(), x.end());
        return lcs(x, s);
    }

    int lcs(string a, string b) {
        int m = a.size(), n = b.size();
        int dp[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[m][n];
    }
};
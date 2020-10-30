// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int min3(int a, int b, int c) {
	return min(min(a, b), c);
}
class Solution
{
public:
	int editDistance(string s, string tr)
	{
		// Code here
		int m = s.length();
		int n = tr.length();
		int t[m + 1][n + 1];

		for (int i = 0; i <= m; i++) {
			for ( int j = 0; j <= n; j++) {
				if (i == 0)
					t[i][j] = j;
				else if (j == 0)
					t[i][j] = i;
				else if (s[i - 1] == tr[j - 1])
					t[i][j] = t[i - 1][j - 1];
				else
					t[i][j] = 1 + min3(t[i][j - 1], t[i - 1][j], t[i - 1][j - 1]);
			}
		}
		return t[m][n];
	}
};

// { Driver Code Starts.
int main() {
	int T;
	cin >> T;
	while (T--)
	{
		string s, t;
		cin >> s >> t;
		Solution ob;
		int ans = ob.editDistance(s, t);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
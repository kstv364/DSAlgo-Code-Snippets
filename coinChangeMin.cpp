// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends





//Complete this function
long long minimumNumberOfCoins(int coins[], int numberOfCoins, int val)
{
	// your code here
	int dp[numberOfCoins + 1][val + 1];

	for (int j = 0; j <= val; j++) {
		dp[0][j] = INT_MAX - 1;
	}

	for (int i = 1; i <= numberOfCoins; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i <= numberOfCoins; i++) {
		for (int j = 1; j <= val; j++) {
			if (coins[i - 1] <= j) {
				dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	if (dp[numberOfCoins][val] == INT_MAX - 1)
		return -1;
	return dp[numberOfCoins][val];
}


// { Driver Code Starts.



int main() {
	int testcases;
	cin >> testcases;
	while (testcases--)
	{
		int value;
		cin >> value;
		int numberOfCoins;
		cin >> numberOfCoins;
		int coins[numberOfCoins];

		for (int i = 0; i < numberOfCoins; i++)
			cin >> coins[i];

		int answer = minimumNumberOfCoins(coins, numberOfCoins, value);
		if (answer == -1)
			cout << "Not Possible" << endl;
		else
			cout << answer << endl;

	}
	return 0;
}  // } Driver Code Ends
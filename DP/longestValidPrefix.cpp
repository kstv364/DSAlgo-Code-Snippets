#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define FOR(i,n) for(long long int i =0 ; i<n;i++)
#define FOR2(i,start,end) for(i=start; i< end; i++)

int solve() {
	string input;
	cin >> input;
	stack<char> st;
	int n = input.length();
	int ans = 0;
	int prefix = 0;
	FOR(i, n) {
		if (input[i] == '<') {
			st.push('<');
		}
		else {
			if (st.empty())
				return ans;
			ans += 2;
			st.pop();
			if (st.empty()) {
				prefix = ans;
			}
		}
	}
	return prefix;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		cout << solve() << endl;
	}
	return 0;
}
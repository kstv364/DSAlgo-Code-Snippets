
/*
Ways to pair n people such that each can be paired with another or stay single

if nth person comes he either stays single
that is ways = ways of n-1 persons

or pair up with any of the n-1 persons

for this case we will be left with n-2 persons and
the person to be paired with can be any of n-1

ways = n-1 * ways of n-2 persons

add them fo find ans for n persons
*/

void testcase() {
	int n;
	cin >> n;
	t[1] = 1;
	t[2] = 2;
	for (int i = 3; i <= n; i++) {
		t[i] = (t[i - 1] % MOD + (i - 1) * t[i - 2]) % MOD;
	}
	cout << t[n] << endl;
}
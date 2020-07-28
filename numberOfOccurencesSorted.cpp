#include<bits/stdc++.h>
using namespace std;

#define long long int ll
#define FOR(i,n) for(int i =0 ; i<n;i++)
#define FOR2(i,start,end) for(i=start; i< end; i++)

int leftmost(vector<int> &arr, int n, int x) {
	int l = 0;
	int r = n - 1;
	int res = -1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (arr[mid] >= x) {
			if (arr[mid] == x) res = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	return res;
}
int rightmost(vector<int> &arr, int n, int x) {
	int l = 0;
	int r = n - 1;
	int res = -1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (arr[mid] <= x) {
			if (arr[mid] == x) res = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return res;
}
int occurence(vector<int> &arr, int n, int x) {
	int l = leftmost(arr, n, x);
	int r = rightmost(arr, n, x);
	if (l != -1)
		return r - l + 1;
	else
		return -1;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, t, x;
		cin >> n >> x;
		vector<int> arr;
		FOR(i, n) {
			cin >> t;
			arr.push_back(t);
		}
		cout << occurence(arr, n, x) << endl;
	}
	return 0;
}
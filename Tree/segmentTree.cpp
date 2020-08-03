// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getMid(int s, int e) {
    return s + (e - s) / 2;
}

ll constructSTUtil(int *arr, int ss, int se, ll *st, int si) {
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, si * 2 + 1) +
             constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);
    return st[si];
}

ll *constructST(int *arr, int n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    ll *st = new ll[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}

ll getsum(ll *st, int n, int l, int r);
void updateValue(int *, ll *, int, int, int);

// Position this line where user code will be pasted

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int num, query;
        cin >> num >> query;
        int arr[num];
        for (int i = 0; i < num; i++) cin >> arr[i];

        ll *st = constructST(arr, num);
        int L, R, index, val;
        char type;
        while (query--) {
            cin.ignore(INT_MAX, '\n');
            cin >> type;
            if (type == 'G') {
                cin >> L >> R;
                cout << getsum(st, num, L, R) << endl;
            } else {
                cin >> index >> val;
                updateValue(arr, st, num, index, val);
            }
        }
    }

    return 0;
}
// } Driver Code Ends


// User function template for C++

// arr : given array
// n : size of arr
// index : need to update
// new_val : given value to which we need to update index
// st : constructed segment-tree
// Functioon use to update the value present in given array arr at index to
// new_val

#define mid(l,r) (l+r)/2
#define lchild(i) (2*i + 1)
#define rchild(i) (2*i + 2)

ll merge(int a, int b, string c) {
    if (c == "add") return a + b;
    if (c == "max") return max(a, b);
    if (c == "min") return min(a, b);
}


ll updateValueutil(ll * st, int i, int l, int r, int x, int y) {
    if (l == r and l == x)   return st[i] = y;
    if (x > r or x < l) return st[i];

    return st[i] = merge(updateValueutil(st, 2 * i + 1, l, mid(l, r), x, y ) , updateValueutil(st, 2 * i + 2, mid(l, r) + 1, r, x, y), "add");

}
void updateValue(int *arr, ll *st, int n, int index, int new_val)
{
    arr[index] = new_val;
    updateValueutil(st, 0, 0, n - 1, index, new_val);
}

// function will return the sum in arr from qs to qe index
ll getsumUtil(ll *st, int i, int l, int r, int ll, int rr) {
    if (l >= ll and r <= rr) return st[i];
    if (rr <= mid(l, r)) return  getsumUtil(st, 2 * i + 1, l, mid(l, r), ll , rr);
    if (ll > mid(l, r)) return getsumUtil(st, 2 * i + 2, mid(l, r) + 1, r, ll , rr);
    return merge(getsumUtil(st, 2 * i + 1, l, mid(l, r), ll , rr) , getsumUtil(st, 2 * i + 2, mid(l, r) + 1, r, ll , rr), "add" );
}

ll getsum(ll *st, int n, int l, int r) {
    return getsumUtil(st, 0, 0, n - 1, l, r);
}

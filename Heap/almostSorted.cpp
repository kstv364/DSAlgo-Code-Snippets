#include <bits/stdc++.h>
using namespace std;



/*
Algorithm
========================

1. push k elements in min heap
2. continue poping min element and printing it.

Works because a number can be out its place by atmost k positions.

so when a number leaves the heap it alreadt has k neighbours to compete with

so k-neighborhood of element is seen and the element is minimum in the k-neighborhood

*/


void solve(int a[], int n, int k) {
    priority_queue <int, vector<int>, greater<int> > pq;
    int i = 0;
    while (k--) {
        pq.push(a[i++]);
    }
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();

        if (i < n) {
            pq.push(a[i++]);
        }
    }
}

void testcase() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(a, n, k);
    cout << endl;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}
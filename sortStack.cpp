// { Driver Code Starts
#include <bits/stdc++.h>
#define ll long long int
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void inputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void recurse(stack<int> &st, int n) {
    if (n > 1) {
        int tmp = st.top();
        st.pop();
        recurse(st, n - 1);
        stack<int> s;
        while (!st.empty() and st.top() < tmp) {
            s.push(st.top());
            st.pop();
        }
        st.push(tmp);
        while (!s.empty()) {
            st.push(s.top());
            s.pop();
        }

    }
}

void sortStack(stack<int> &st) {
    recurse(st, st.size());
}

void printStack(stack<int> &st) {
    stack<int> tmp;
    while (!st.empty()) {
        tmp.push(st.top());
        cout << st.top() << endl;
        st.pop();
    }
    while (!tmp.empty()) {
        st.push(tmp.top());
        tmp.pop();

    }
}

int main() {

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int a[n];
        inputArray(a, n);
        printArray(a, n);
        stack<int> s;
        FOR(i, n) {
            s.push(a[i]);
        }
        sortStack(s);
        printStack(s);
    }

    return 0;
}// } Driver Code Ends


// { Driver Code Starts
#include <bits/stdc++.h>
#define ll long long int
#define FOR(i,n) for(int i=0;i<n;i++)


using namespace std;


void inplaceInsert(int arr[], int upto) {
    int tmp = arr[upto];
    while (upto > 0 and tmp < arr[upto - 1]) {
        arr[upto] = arr[upto - 1];
        upto--;
    }
    arr[upto] = tmp;
}

void recurse(int arr[], int n) {
    if (n > 0) {
        recurse(arr, n - 1);
        inplaceInsert(arr, n);
    }

}
void sort(int arr[], int n) {
    recurse(arr, n - 1);
}

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


int main() {

    int n;

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        int a[n];
        inputArray(a, n);
        printArray(a, n);
        sort(a, n);
        printArray(a, n);
    }

    return 0;
}// } Driver Code Ends


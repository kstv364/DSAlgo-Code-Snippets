int leftIndex(int N, int arr[], int X) {

    // Your code here
    int l = 0;
    int r = N - 1;
    int res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] >= X) {
            if (arr[mid] == X)
                res = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return res;
}
long merge(vector<int> &arr, vector<int> &temp, int l, int mid , int r) {
    long invcount = 0;
    int i = l, j = mid + 1, k = l;
    while (i <= mid and j <= r) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];

            // if arr[i]>arr[j]
            // all elements from i to mid are greate than j
            // #inversions = mid - i + 1
            invcount += mid - i + 1;
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= l) temp[k++] = arr[j++];

    for (k = l; k <= r; k++) arr[k] = temp[k];
    return invcount;
}

long mergesort(vector<int> &arr, vector<int> &temp, int l, int r) {
    long invcount = 0;
    if (l < r) {
        int mid = l + (r - l) / 2;
        invcount = mergesort(arr, temp, l, mid);
        invcount += mergesort(arr, temp, mid + 1, r);
        invcount += merge(arr, temp, l, mid , r);
    }
    return invcount;
}
// Complete the countInversions function below.
long countInversions(vector<int> arr) {
    vector<int> temp(arr);
    return mergesort(arr, temp, 0, arr.size() - 1);

}
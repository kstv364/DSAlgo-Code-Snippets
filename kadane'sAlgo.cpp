
void kadanes(int arr[], int n) {
	int max_so_far = arr[0];
	int curr_max = arr[0];

	// curr_max should never be negative
	// if all numbers are negative max_so_far
	// should be maxmum among them
	curr_max = max(curr_max, 0);

	// curr_max = 0

	for (int i = 1; i < n; i++) {
		curr_max += arr[i];
		max_so_far = max(max_so_far, curr_max);
		curr_max = max(curr_max, 0);// curr_max should never be negative
	}
	cout << max_so_far << endl;
}


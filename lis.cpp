// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
  int t, n;
  cin >> t;
  while (t--)
  {
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];

    cout << longestSubsequence(n, a) << endl;
  }
}
// } Driver Code Ends


// return length of longest strictly increasing subsequence

int longestSubsequence(int n, int a[])
{
  // your code here

  // need to find lis ending with ith element for all elements

  int lis[n];

  lis[0] = 1;
  for (int i = 1; i < n; i++) {
    lis[i] = 1; // min value of lis[i] has to be 1
    // since atleast there would be one subsequence with the element

    //check for all the elements lesser than current element
    // if previous element is smaller than current we can append
    // current to the lis ending with previous element to get a larger sequence
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) { // strictly increasing
        lis[i] = max(lis[i], lis[j] + 1);
      }
    }
  }

  // lis ending with each element is built now

  int res = lis[0]; // =1
  for (int i = 1; i < n; i++) {
    res = max(res, lis[i]);
  }
  return res;
}

void nextGreaterElement() {
    int n;
    cin >> n;
    int a[n], ans[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() and s.top() <= a[i]) s.pop();
        if (s.empty())   ans[i] = -1;
        else    ans[i] = s.top();
        s.push(a[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

}

/*
FOR CIRCULAR SEARCH
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& t) {

        int n = t.size();
        if (n == 0) return {};
        t.insert(t.end(), t.begin(), t.end());
        int ans[2 * n];
        stack<int> s;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!s.empty() and t[i] >= s.top()) s.pop();
            if (s.empty()) ans[i] = -1;
            else ans[i] = s.top();
            s.push(t[i]);
        }
        return vector<int> (ans, ans + n);
    }
};

/*
ALTERNATE
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack <int> s;
        for (int i = n - 1; i >= 0; i--) s.push(nums[i]);
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i]) {
                s.pop();
            }
            ans[i] = s.empty() ? -1 : s.top();
            s.push(nums[i]);
        }
        return ans;
    }
};
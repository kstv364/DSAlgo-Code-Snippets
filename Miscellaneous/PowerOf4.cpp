
/*
IMPORTANT

CAN BE EXTENDED FOR ANY VALUE

*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1)
            return true;
        queue<int> q;

        // using base conversion
        while (n > 0) {
            q.push(n % 4);
            n = n / 4;
        }
        if (q.front() != 0)
            return false;
        while (q.front() == 0) {
            q.pop();
        }
        return q.size() == 1 and q.front() == 1;
    }
};
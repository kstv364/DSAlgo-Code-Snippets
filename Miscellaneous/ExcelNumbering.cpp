class Solution {
public:
    string convertToTitle(int n) {
        string v = "";
        while (n > 0) {
            if (n % 26 != 0) {
                v.push_back((char)64 + n % 26);
                n = n / 26;
            }
            else {
                v.push_back('Z');
                n = n / 26 - 1;
            }
        }
        reverse(v.begin(), v.end());
        return v;



    }
};
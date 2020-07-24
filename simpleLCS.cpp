int lcs(int x, int y, string s1, string s2) {

    // your code here

    int lcs[x + 1][y + 1];


    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (i == 0 or j == 0)
                lcs[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1]) {
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            }
            else {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
    return lcs[x][y];

}
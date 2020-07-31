void rec(string curr, int o, int c) {
    if (o == 0 and c == 0) {
        cout << curr << endl;
        return;
    }
    if (o != 0) {
        curr.push_back('(');
        rec(curr, o - 1, c);
        curr.pop_back();

    }
    else if (c > o) {
        curr.push_back(')');
        rec(curr, o , c - 1);
        curr.pop_back();
    }

}
void getvalid(int n) {
    string curr = "";
    rec(curr, n, n);
}
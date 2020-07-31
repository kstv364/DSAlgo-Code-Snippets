/*
Diameter is just l + r + 1
but diameter may not pass through root
hence calculate for all nodes and pick maximum

*/
int solve(Node *node, int &ans) {
    if (!node)
        return 0;
    int l , r;
    l = solve(node->left, ans);
    r = solve(node->right, ans);
    ans = max(ans, l + r + 1);
    return max(l, r) + 1;
}
/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
    int ans = INT_MIN;
    solve(node, ans);
    return ans;
}

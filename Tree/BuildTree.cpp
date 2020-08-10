
/*
FROM INORDER AND POSTORDER
*/

int p = 0;
unordered_map<int, int> mp;

Node * util(int in[], int post[], int l, int r, int n) {
    if (l > r) return nullptr;
    Node * root = new Node(post[p--]);
    int mid = mp[root->data];
    root->right = util(in, post, mid + 1 , r, n );
    root->left = util(in, post, l, mid - 1, n);
    return root;

}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    p = n - 1;
    mp.clear();
    for (int i = 0; i < n; i++) mp[in[i]] = i;
    return util(in, post, 0, n - 1, n);
}



/*
FROM INORDER AND PREORDER
*/
int p = 0;
unordered_map<int, int> mp;

Node * util(int in[], int pre[], int l, int r, int n) {
    if (l > r) return nullptr;
    Node * root = new Node(pre[p++]);
    int mid = mp[root->data];

    root->left = util(in, pre, l, mid - 1, n);
    root->right = util(in, pre, mid + 1 , r, n );
    return root;

}
Node *buildTree(int in[], int pre[], int n) {
    // Your code here
    p = 0;
    mp.clear();
    for (int i = 0; i < n; i++) mp[in[i]] = i;
    return util(in, pre, 0, n - 1, n);
}

void convert(Node *head, TreeNode *&root) {
    // Your code here
    if (!head) return;
    queue<TreeNode *> q;
    root = new TreeNode(head->data);
    head = head->next;
    q.push(root);
    while (head) {
        TreeNode *parent = q.front();
        q.pop();

        TreeNode *left = nullptr, *right =  nullptr;
        left = new TreeNode(head->data);
        head = head->next;
        q.push(left);
        if (head) {
            right = new TreeNode(head->data);
            head = head->next;
            q.push(right);
        }
        parent->left = left;
        parent->right = right;

    }
}

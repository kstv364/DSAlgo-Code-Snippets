void printSpiral(Node *root)
{
    //Your code here
    queue<Node*> q;
    stack<Node*> s;
    bool dir = true;
    if (!root) return;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            Node * curr = q.front();
            q.pop();

            if (dir)
                s.push(curr);
            else
                cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        dir = !dir;
        while (!s.empty()) {
            cout << s.top()->data << " "; s.pop();
        }
    }
}

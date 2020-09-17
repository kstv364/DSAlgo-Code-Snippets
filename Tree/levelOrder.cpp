void levelOrder(Node* node)
{
    //Your code here
    queue<Node*> q;
    q.push(node);
    //q.push(NULL);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            Node * curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }
        cout << "$ ";
    }
}



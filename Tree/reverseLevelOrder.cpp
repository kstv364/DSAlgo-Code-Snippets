void reversePrint(Node *root)
{
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> ans;
    while (!q.empty()) {
        int size = q.size();
        ans.push_back(vector<int> ());
        while (size--) {
            Node * curr = q.front(); q.pop();
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
            ans[ans.size() - 1].push_back(curr->data);
        }
    }

    for (int i = ans.size() - 1 ; i >= 0 ; i--) {
        for (auto x : ans[i]) {
            cout << x << " ";
        }
    }

}
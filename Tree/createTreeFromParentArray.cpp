Node *createTree(int parent[], int n)
{
    // Your code here
    Node * root;
    Node * nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = new Node(i);
    }

    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) root = nodes[i];
        else {
            if (!nodes[parent[i]]->left)
                nodes[parent[i]]->left = nodes[i];
            else
                nodes[parent[i]]->right = nodes[i];
        }
    }
    return root;
}
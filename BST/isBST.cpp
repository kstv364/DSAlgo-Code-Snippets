bool isBSTUtil(struct Node* root, Node *&prev)
{
    // traverse the tree in inorder fashion and
    // keep track of prev node
    if (root)
    {
        if (!isBSTUtil(root->left, prev))
            return false;

        // Allows only distinct valued nodes
        if (prev != NULL && root->data <= prev->data)
            return false;

        prev = root;

        return isBSTUtil(root->right, prev);
    }

    return true;
}


bool isBST(Node* node)
{
    return isBSTUtil(node, INT_MIN, INT_MAX);
}

/* Returns true if the given
tree is a BST and its values
are >= min and <= max. */
int isBSTUtil(Node* node, int min, int max)
{
    if (!node) return 1;
    if (node->data <= max and node->data >= min)
        return isBSTUtil(node->left, min , node->data ) &&
               isBSTUtil(node->right, node->data + 1, max);
    return 0;
}

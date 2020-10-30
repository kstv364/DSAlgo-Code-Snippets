// Returns the LCA of the nodes with values n1 and n2
// in the BST rooted at 'root' 
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   int a = max(n2,n1);
   int b = min(n1,n2);
   n2 = a;
   n1 = b;
   if(!root) return NULL;
   if(n1< root->data and n2<root->data)
        return LCA(root->left, n1 , n2);
    else if(n1> root->data and n2 > root->data)
        return LCA(root->right, n1, n2);
    else if(n1<=root->data and n2>=root->data)
        return root;
}

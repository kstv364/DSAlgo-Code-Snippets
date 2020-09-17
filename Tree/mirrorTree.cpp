void mirror(Node* node)
{
	// Your Code Here
	if (!node) return;
	Node * temp;
	temp = node->left;
	node->left = node->right;
	node->right = temp;
	mirror(node->left);
	mirror(node->right);
}
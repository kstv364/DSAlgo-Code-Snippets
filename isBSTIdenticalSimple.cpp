bool isIdentical(Node *r1, Node *r2)
{
	//Your Code here
	if (r1 == NULL and r2 == NULL)
		return true;
	if (r1 and r2 and r1->data == r2->data) {
		return isIdentical(r1->left, r2->left) and
		       isIdentical(r1->right, r2->right);
	}
	return false;
}
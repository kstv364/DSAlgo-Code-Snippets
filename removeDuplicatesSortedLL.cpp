Node *removeDuplicates(Node *root)
{
// your code goes here
    if (root) {
        Node *head = new Node(root->data);
        Node *p1 = head;
        while (root) {
            if (root->data == p1->data) {
            }
            else {
                p1->next = new Node(root->data);
                p1 = p1->next;
            }
            root = root->next;
        }
        return head;

    }

    return root;

}
Node* rotate(Node* head, int k)
{
    // Your code here
    if (head) {

        // Find length
        Node * p = head;
        int l = 1;
        while (p->next) {
            p = p->next;
            l++;
        }

        /// find rotation
        k = k % l;

        // if no rotation needed do nothing
        if (k != 0) {
            p -> next = head;
            p = head;
            Node *prev = NULL;
            while (k--) {
                prev = head;
                head = head->next;
            }
            if (prev)
                prev->next = NULL;
        }
        return head;
    }
    return NULL;
}

Node* pairWiseSwap(struct Node* head) {
    // The task is to complete this method
    if (head and head->next) {
        Node *p  = head->next->next;
        Node *h2 = head->next;
        h2 ->next = head;
        head->next = pairWiseSwap(p);
        return h2;
    }
    else {
        return head;
    }
}
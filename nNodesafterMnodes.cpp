void linkdelete(struct Node  *head, int M, int N)
{
    //Add code here
    if (head) {
        Node *p = head, *prv = NULL;
        int k = M, l = N;
        while (k-- and p) {
            prv = p;
            p = p->next;
        }
        Node *q = prv;
        while (p and l--) {
            p = p->next;
        }
        prv->next = p;
        linkdelete(prv->next, M, N);
    }

}


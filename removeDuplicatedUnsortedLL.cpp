Node * removeDuplicates( Node *head)
{
// your code goes here
    unordered_set<int> st;
    vector<int> v;
    while (head) {
        if (st.find(head->data) == st.end()) {
            st.insert(head->data);
            v.push_back(head->data);
        }


        head = head->next;
    }
    Node *curr;
    head = NULL;
    for (auto it = v.begin(); it != v.end(); it++) {
        if (!head) {
            head = new Node(*it);
            curr = head;
        }
        else {
            curr->next = new Node(*it);
            curr = curr->next;
        }
    }
    return head;
}

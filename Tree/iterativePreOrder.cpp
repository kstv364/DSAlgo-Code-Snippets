vector <int> preOrder(struct Node* node)
{
    //Your code here
    stack<struct Node*> st;
    Node * curr ;
    vector<int> v;
    if (node)
        st.push(node);
    else
        return v;

    while (!st.empty()) {
        curr = st.top(); st.pop();
        v.push_back(curr->data);
        if (curr->right) {
            st.push(curr->right);
        }
        if (curr->left) {
            st.push(curr->left);
        }
    }

}


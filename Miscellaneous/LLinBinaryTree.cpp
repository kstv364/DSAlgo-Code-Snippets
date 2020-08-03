
// Difficult problem

class Solution {
public:

    ListNode* actualHead;
    bool util(ListNode* head, TreeNode* root) {
        if (!root) return head ? false : true;
        if (!head) return true;
        if (root->val != head->val)
            head = actualHead;
        if (root->val == head->val)
            head = head ->next;
        return util(head, root->left) || util(head, root->right);


    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        actualHead = head;
        return util(head, root) || isSubPath(head, root->left ) || isSubPath(head, root->right);
    }
};
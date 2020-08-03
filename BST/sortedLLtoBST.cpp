/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:


    TreeNode* sortedListToBST(ListNode* head) {
        // edge case 1->2->3->4->X
        // mid = 3
        if (!head) return nullptr;


        ListNode *slow, *fast, *prev = nullptr;

        // find mid
        slow = fast = head;
        while (fast and fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // if slow and fast did not move only 1 node
        if (slow == fast) return  new TreeNode(slow->val);

        // need to end left part of LL
        if (prev) prev->next = nullptr;

        // create new Treenode with mid
        TreeNode *newnode = new TreeNode(slow->val);
        newnode->left = sortedListToBST(head);
        newnode->right = sortedListToBST(slow->next);
        return newnode;
    }
};
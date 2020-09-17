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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        return (modifiedHeight(root) != -1) ? true : false;
    }

    int modifiedHeight(TreeNode* root) {
        if (!root) return 0;

        int l , r;
        l = modifiedHeight(root->left);
        r = modifiedHeight(root->right);

        if (l == -1 || r == -1) return -1;

        if ( abs(l - r ) <= 1)
            return max(l, r) + 1;

        return -1;
    }
};
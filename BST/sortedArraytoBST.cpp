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
    TreeNode* util(vector<int>& nums, int l, int r) {
        if (r < l) return nullptr;
        if (l == r) return new TreeNode(nums[l]);

        int mid = l + (r - l) / 2;
        TreeNode* newnode = new TreeNode(nums[mid]);
        newnode->left = util(nums, l, mid - 1);
        newnode->right = util(nums, mid + 1, r);
        return newnode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return util(nums, 0, nums.size() - 1);
    }
};
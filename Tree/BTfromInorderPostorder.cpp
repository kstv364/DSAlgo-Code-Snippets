class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return util(inorder, postorder, 0, postorder.size() - 1, postorder.size() - 1);
    }

    TreeNode * util(vector<int>& inorder, vector<int>& postorder, int start, int end , int index) {
        if (start > end) return nullptr;
        TreeNode * root = new TreeNode(postorder[index]);
        int mid = -1;
        for (int i = start; i <= end; i++) {
            if (inorder[i] == postorder[index])
                mid = i;
        }
        root->right = util(inorder, postorder, mid + 1, end, index - 1 );
        root->left = util(inorder, postorder, start, mid - 1, index - 1 - (end - mid)); // important
        return root;

    }
};
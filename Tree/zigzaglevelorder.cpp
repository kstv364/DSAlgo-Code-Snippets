class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        q.push(nullptr);
        bool r2l = false;
        vector<int> tmp;
        if (root == nullptr)  return ans;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr) {
                tmp.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            else {
                if (!q.empty())
                    q.push(nullptr);
                if (r2l) {
                    reverse(tmp.begin(), tmp.end());
                }
                r2l = !r2l;
                ans.push_back(vector<int> (tmp));
                tmp.clear();
            }

        }

        return ans;
    }
};
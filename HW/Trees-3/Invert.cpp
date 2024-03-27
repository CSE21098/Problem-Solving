class Solution {
public:
     TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return NULL;
        TreeNode* swap = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = swap;
        return root;
    }
};
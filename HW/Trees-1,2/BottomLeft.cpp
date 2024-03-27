class Solution {
public:
    int ans=0, level=-1;
    void dfs(TreeNode* node, int h){
        if (!node) return;

        if (h>level){
            ans=node->val;
            level=h;
        } 
        dfs(node->left, h+1);
        dfs(node->right, h+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
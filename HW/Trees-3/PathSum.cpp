class Solution {
public:
    int solve(TreeNode *root,int target){
        if(root==NULL){
            return 0;
        }
        if(!root->right && !root->left){
            if(target==root->val){
                return 1;
            }
        }
        int left = solve(root->left,target-root->val);
        int right = solve(root->right,target-root->val);
        if(left||right){
            return 1;
        }
        return 0;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum);
    }
};
class Solution {
public:
    bool isBST(TreeNode* root,long long minval,long long maxval){
        if(root==NULL){
            return true;
        }
        if(root->val>= minval && root->val <= maxval){
            bool left= isBST(root->left,minval,root->val-1LL);
            bool right= isBST(root->right,root->val+1LL,maxval);
            return left && right;
        }
        else{
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root,LLONG_MIN,LLONG_MAX);
    }
};
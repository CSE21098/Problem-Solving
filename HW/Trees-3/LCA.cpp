class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }

        if(root->val==p->val || root->val==q->val){
            return root;
        }
        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
        
        if(leftAns && rightAns){
            return root;
        }
        else if(leftAns && rightAns==NULL){
            return leftAns;
        }
        else if(rightAns && leftAns==NULL){
            return rightAns;
        }
        else{
            return NULL;
        }
    }
};
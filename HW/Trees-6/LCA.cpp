class Solution {
public:
    TreeNode* find(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root->val<p->val &&root->val<q->val){
            return find(root->right,p,q);
        }
        if(root->val>p->val &&root->val>q->val){
            return find(root->left,p,q);
        }
        if((root->val>p->val && root->val<q->val) || (root->val<p->val && root->val>q->val)){
            return root;
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val==q->val || root->val==q->val){
            return root;
        }
        TreeNode* ans = find(root,p,q);
        return ans;
    }
};
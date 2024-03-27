class Solution {
public:
    bool equal(int p, int q){
        if(p==q){
            return true;
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        TreeNode* root1= p;
        TreeNode* root2= q;
         
        if(root1==NULL && root2==NULL){
            return true;
        }
        if(root1 && root2==NULL){
            return false;
        }
        if(root2 && root1==NULL){
            return false;
        }
        bool left = isSameTree(root1->left,root2->left) && equal(root1->val,root2->val);
        bool right = isSameTree(root1->right,root2->right) && equal(root1->val,root2->val);
        if(left && right){
            return true;
        }
        return false;
    }
};
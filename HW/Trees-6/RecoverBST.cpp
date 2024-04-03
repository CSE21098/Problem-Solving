class Solution {
public:
    TreeNode* fst;
    TreeNode* scnd;
    TreeNode* prv;
    TreeNode* nxt;
    void recoverTree(TreeNode* root) {
        fst=NULL;
        scnd=NULL;
        nxt=NULL;
        prv=new TreeNode(INT_MIN);
        trav(root);
        if(fst && scnd){swap(fst->val, scnd->val);}
        else if(fst && nxt){swap(fst->val , nxt->val);}
    }
    void trav(TreeNode* root){
        if(!root){return;}
        trav(root->left);
        if(prv && (root->val<prv->val)){
            if(!fst){
                fst=prv;
                nxt=root;
            }
            else{
                scnd=root;
            }
        }
        prv=root;
        trav(root->right);
    }
};
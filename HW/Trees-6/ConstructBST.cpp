class Solution {
public:
    void insertIntoBST(TreeNode* &root,int data){
        if(root==NULL){
            root=new TreeNode(data);
            return ;
        }
        if(data>root->val){
            insertIntoBST(root->right,data);
        }
        else{
            insertIntoBST(root->left,data);
        }
        return ;
    }
    TreeNode* bstFromPreorder(vector<int>& preor) {
        int i=0;
        TreeNode * ans;
        while(i<preor.size()){
            insertIntoBST(ans,preor[i]);
            i++;
        }
        return ans;
    }
};
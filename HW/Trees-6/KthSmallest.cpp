class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans){
        
        if(root==NULL){
            return ;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root,ans);
        int i=0,data=0;
        while(i<k){
            data=ans[i];
            i++;
        }
        return data;
    }
};
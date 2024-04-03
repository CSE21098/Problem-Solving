class Solution {
public:
    void solve(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> ans;
        solve(root,ans);
        int temp=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]>=low && ans[i]<=high){
                temp+= ans[i];
            }
        }
        return temp;

    }
};
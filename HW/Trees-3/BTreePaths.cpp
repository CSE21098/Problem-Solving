class Solution {
public:
    void dfs(vector<string>&ans, string curr,TreeNode* root){
        if(!root->left && !root->right){
            curr+=to_string(root->val);
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        curr+=to_string(root->val) +"->";

        if(root->left!=NULL){
            dfs(ans,curr,root->left);
        }
        if(root->right!=NULL){
            dfs(ans,curr,root->right);
        }
        curr.pop_back();
        curr.pop_back();
    }  
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string curr;
        dfs(ans,curr,root);
        return ans;
    }
};
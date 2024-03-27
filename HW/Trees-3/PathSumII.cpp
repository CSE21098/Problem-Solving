class Solution {
public:
   void solve(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int> path, int sum ){
        if(root == NULL){
            return;
        }
        sum += root->val;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                ans.push_back(path);
            }
            else{
                return;
            }
        }
        solve(root->left, targetSum, ans, path, sum);
        solve(root->right, targetSum, ans, path, sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int> path;
        int sum = 0;
        solve(root, targetSum, ans, path, sum);
        return ans;
    }
};
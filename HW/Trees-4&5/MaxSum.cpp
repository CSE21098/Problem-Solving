class Solution {
public:
    int sum = 0;
    pair<int,pair<int,int>> helper(TreeNode *root){
		if(root == NULL){
            return {0, {INT_MAX, INT_MIN}};
        }
        pair<int,pair<int,int>> lst = helper(root->left);
        pair<int,pair<int,int>> rst = helper(root->right);
        
        if(lst.second.second < root->val && root->val < rst.second.first){
            int s = root->val + lst.first + rst.first;
            sum = max(sum, s);
            int mi = min({root->val, lst.second.first, rst.second.first});
            int ma = max({root->val, lst.second.second, rst.second.second});
            return {s, {mi, ma}};
        }
        return {0, {INT_MIN, INT_MAX}};
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return sum;
    }
};
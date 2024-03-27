class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(root==NULL){
            return vec;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> ans;
            for(int i=0; i<size; i++) {
                TreeNode * temp= q.front();
                q.pop();
                ans.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            vec.push_back(ans);
        }
        return vec;
    }
};
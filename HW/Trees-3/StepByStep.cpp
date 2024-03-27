class Solution {
    string ans1,ans2;

    TreeNode* lca(TreeNode* root,int p,int q){
        if (!root) return nullptr;
        if (root->val==p || root->val==q) return root;
        TreeNode* left = lca(root->left,p,q);
        TreeNode* right = lca(root->right,p,q);
        if (left && right) return root;
        else if (left) return left;
        else return right;
    }

    void dfs(TreeNode* root,int& start,int& dest, string& path){
        if (!root) return;
        if (root->val==start) ans1=path;
        if (root->val==dest) ans2=path;
        path+="L";
        dfs(root->left,start,dest,path);
        path.pop_back();
        path+="R";
        dfs(root->right,start,dest,path);
        path.pop_back();
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        if (!root) return "";
        ans1="";ans2="";
        string path;
        TreeNode* lowestCommonAncestor=lca(root, startValue,destValue);
        dfs(lowestCommonAncestor,startValue,destValue,path);
        return string(ans1.size(),'U')+ans2;
    }
};
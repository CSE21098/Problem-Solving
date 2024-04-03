class Solution{
    public:
    vector<int> solve(Node* root){
        if(root==NULL){
            return {INT_MIN,INT_MAX,0};
        }
        
        auto l = solve(root->left);
        auto r = solve(root->right);
        
        int leftMax = l[0];
        int rightMin = r[1];
        
        if(leftMax < root->data && root->data < rightMin){
            return {max(l[0],max(r[0],root->data)),
                    min(l[1],min(r[1],root->data)),
                    l[2] + r[2] + 1};
        }
        return {INT_MAX,INT_MIN,max(l[2],r[2])};
    }
    int largestBst(Node *root)
    {
    	vector<int> ans = solve(root);
    	return ans[2];
    }
};
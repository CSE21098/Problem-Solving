class Solution{
  public:
    /*You are required to complete this function*/
    void solve(Node*root,int l,int &odd,int &even){
        if(root==NULL){
            return;
        }
        if(l%2){
            odd +=root->data;
        }
        else{
            even+=root->data;
        }
            solve(root->left,l+1,odd,even);
            solve(root->right,l+1,odd,even);
    }
    int getLevelDiff(Node *root)
    {
       int odd=0,even=0;
       solve(root,1,odd,even);
       return odd-even;
    }
};
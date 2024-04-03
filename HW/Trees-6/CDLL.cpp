class Solution
{
  public:
    Node *prev=NULL,*head=NULL;
    Node *bTreeToCList(Node *root)
    {
    
        if(root==NULL)
        return root;
        bTreeToCList(root->left);
        if(prev==NULL)
        head=root;
        else{
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        bTreeToCList(root->right);
        
        prev->right=head;
        head->left=prev;
        return head;
    }
};
class Solution {
public:
    TreeNode* helper(ListNode*& head,int size){
        if(head==NULL ||size<=0) return NULL;
        int rightSize = (size-1)/2; 
        TreeNode* left = helper(head,size-1-rightSize);
        TreeNode* root = new TreeNode(head->val);
        head = head->next;
        root->left = left;
        root->right = helper(head,rightSize);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int size=0;
        ListNode *save=head;
        while(head){
            size++;
            head = head->next;
        }
        head = save;
        TreeNode* root = helper(head,size);
        return root;
    }
};
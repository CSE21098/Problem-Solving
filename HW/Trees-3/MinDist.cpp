int findDist(Node* root, int a, int b) {
       unordered_map<Node*,Node*>parent;
       unordered_map<int,int>vis;
       Node* node = NULL;
       parent[root] = NULL;
       help(parent,vis,root,a,&node);
       
       return help1(parent,vis,node,b);
    }
    void help(unordered_map<Node*,Node*>&parent,unordered_map<int,int>&vis,Node*root,int a, Node**node)
    {
        if(root == NULL){
            return;
        }
        vis[root->data] = 0;
        if(root->data == a){
            *node = root;
        }
        if(root->left!= NULL){
            parent[root->left] = root;
            help(parent,vis,root->left,a,node);
        }
        if(root->right!= NULL){
            parent[root->right] = root;
            help(parent,vis,root->right,a,node);
        }
    }
    int help1(unordered_map<Node*,Node*>&parent,unordered_map<int,int>&vis,Node* root , int b)
    {
        if(root == NULL){
            return 1e9;
        }
        vis[root->data] = 1;
        if(root->data == b){
            return 0;
        }
        int lef = 1e9;
        int rig = 1e9;
        int par = 1e9;
        if(root->left!= NULL && vis[root->left->data] == 0){
            lef = 1 + help1(parent,vis,root->left,b);
        }
        if(root->right!= NULL && vis[root->right->data] == 0){
            rig = 1 + help1(parent,vis,root->right,b);
        }
        if(parent[root]!=NULL && vis[parent[root]->data] == 0){
            par = 1+help1(parent,vis,parent[root],b);
        }
        return min(lef,min(rig,par));
    }
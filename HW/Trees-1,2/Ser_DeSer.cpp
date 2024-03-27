class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == nullptr) return ".,";
        string s = to_string(root->val) + ",";
        s += serialize(root->left);
        s += serialize(root->right);
        return s;
    }
    int idx = 0;
    TreeNode* deser(vector<int> &v){
        if (v[idx] == 1001) return nullptr;
        auto root = new TreeNode(v[idx]);
        idx ++;
        root -> left = deser(v);
        idx++;
        root -> right = deser(v);
        return root;
    }
    TreeNode* deserialize(string data) {
        vector<int> preOrder; 
        string t;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] != ',' && data[i] != '.') t += data[i];
            else if (data[i] == '.'){
                preOrder.push_back(1001);
            }
            else {
                if (t.size()){
                    preOrder.push_back(stoi(t));
                    t = "";
                }               
            }
        } 
        if (preOrder.size()==1) return nullptr;
        return deser(preOrder) ;     
    }
};
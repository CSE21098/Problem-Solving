class Solution {
public:
    void inorderTraversal(Node* root, vector<int>& inorder) {
        if (root == nullptr) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->data);
        inorderTraversal(root->right, inorder);
    }

    vector<int> mergeSortedVectors(const vector<int>& v1, const vector<int>& v2) {
        vector<int> merged;
        int i = 0, j = 0;

        while (i < v1.size() && j < v2.size()) {
            if (v1[i] < v2[j]) {
                merged.push_back(v1[i]);
                i++;
            } else {
                merged.push_back(v2[j]);
                j++;
            }
        }

        while (i < v1.size()) {
            merged.push_back(v1[i]);
            i++;
        }

        while (j < v2.size()) {
            merged.push_back(v2[j]);
            j++;
        }

        return merged;
    }

    vector<int> merge(Node* root1, Node* root2) {
        vector<int> inorder1;
        vector<int> inorder2;
        
        inorderTraversal(root1, inorder1);
        inorderTraversal(root2, inorder2);
        
        vector<int> merged = mergeSortedVectors(inorder1, inorder2);
        
        sort(merged.begin(), merged.end());
        
        return merged;
    }
};

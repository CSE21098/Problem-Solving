void leftBoundary(TreeNode<int> *node, vector<int> &result) {
    if (node == nullptr) return;
    if (node->left || node->right) result.push_back(node->data);
    if (node->left) leftBoundary(node->left, result);
    else leftBoundary(node->right, result);
}

void rightBoundary(TreeNode<int> *node, vector<int> &result) {
    if (node == nullptr) return;
    if (node->right) rightBoundary(node->right, result);
    else rightBoundary(node->left, result);
    if (node->left || node->right) result.push_back(node->data);
}

void leafNodes(TreeNode<int> *node, vector<int> &result) {
    if (node == nullptr) return;
    if (!node->left && !node->right) result.push_back(node->data);

    leafNodes(node->left, result);
    leafNodes(node->right, result);
}

vector<int> traverseBoundary(TreeNode<int> *root) {
    if (root == nullptr) return {};
    vector<int> result;
    result.push_back(root->data);
    leftBoundary(root->left, result);
    leafNodes(root, result);
    rightBoundary(root->right, result);
    return result;
}
class Solution{
public:
    Node* cloneGraph(Node* node, map<Node*, Node*>& mp) {
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        for (auto neighbor : node->neighbors) {
            if (mp.find(neighbor) != mp.end()) {
                newNode->neighbors.push_back(mp[neighbor]);

            } else {
                newNode->neighbors.push_back(cloneGraph(neighbor, mp));
            }
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        map<Node*, Node*> mp;
        Node* ans = cloneGraph(node, mp);
        return ans;
    }
};
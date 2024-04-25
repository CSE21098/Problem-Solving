class Solution {
public:
    int minimumEdgeReversal(vector<vector<int>>& edges, int n, int src, int dst) {
        vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].emplace_back(v, 0);
            adj[v].emplace_back(u, 1);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n + 1, false);
        vector<int> ans(n + 1, INT_MAX);
        ans[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            int dist = p.first;
            int node = p.second;
            if (visited[node]) 
                continue;
            visited[node] = true;
            for (pair<int, int>& p2 : adj[node]) {
                int nbrNode = p2.first;
                int nbrWt = p2.second;
                if (ans[node] + nbrWt < ans[nbrNode]) {
                    ans[nbrNode] = ans[node] + nbrWt;
                    pq.push({ans[nbrNode], nbrNode});
                }
            }
        }
        return (ans[dst] == INT_MAX) ? -1 : ans[dst];
    }
};
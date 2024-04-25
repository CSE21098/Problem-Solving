class Solution {
public:
    using ll = long long;
    using node = pair<ll, ll>;
    vector<ll> minCost(int n, int source, int destination, vector<vector<node>>& graph) {
        vector<ll> distanceFromSource(n, 1e14);
        distanceFromSource[source] = 0;
        priority_queue<node, vector<node>, greater<node>> pq;
        pq.push({0, source});
        while (!pq.empty()) {
            node current = pq.top();
            pq.pop();
            if (current.first > distanceFromSource[current.second]) 
                continue;
            for (auto& adj : graph[current.second]) {
                if (current.first + adj.second < distanceFromSource[adj.first]) {
                    distanceFromSource[adj.first] = current.first + adj.second;
                    pq.push({distanceFromSource[adj.first], adj.first});
                }
            }
        }
        return distanceFromSource;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<node>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<bool> ans(edges.size(), false);
        vector<ll> distanceFromStartToEnd = minCost(n, 0, n - 1, graph);
        vector<ll> distanceFromEndToStart = minCost(n, n - 1, 0, graph);
        ll minDist = distanceFromStartToEnd[n - 1];
        if (minDist == 1e14) 
            return ans;
        for (int i = 0; i < edges.size(); ++i) {
            auto& e = edges[i];
            if ((distanceFromStartToEnd[e[0]] + distanceFromEndToStart[e[1]] + e[2] == minDist) ||
                (distanceFromStartToEnd[e[1]] + distanceFromEndToStart[e[0]] + e[2] == minDist)) {
                ans[i] = true;
            }
        }
        return ans;
    }
};
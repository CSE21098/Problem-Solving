class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph[i].emplace_back(j, dist);
                graph[j].emplace_back(i, dist);
            }
        }
        int minCost = 0;
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.emplace(0, 0);
        while (!minHeap.empty()) {
            auto [cost, node] = minHeap.top();
            minHeap.pop();
            if (!visited[node]) {
                visited[node] = true;
                minCost += cost;
                for (const auto& [neighbor, dist] : graph[node]) {
                    if (!visited[neighbor])
                        minHeap.emplace(dist, neighbor);
                }
            }
        }

        return minCost;
    }
};
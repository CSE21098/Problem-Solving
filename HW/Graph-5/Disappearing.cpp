class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], time = edge[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<int> answer(n, -1);
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int time = current.first, node = current.second;
            if (answer[node] != -1)
                continue;
            answer[node] = time;
            if (graph.count(node)) {
                for (auto& neighbor : graph[node]) {
                    int nextNode = neighbor.first, nextTime = neighbor.second;
                    if (answer[nextNode] == -1 && time + nextTime < disappear[nextNode]) {
                        pq.push({time + nextTime, nextNode});
                    }
                }
            }
        }
        return answer;
    }
};
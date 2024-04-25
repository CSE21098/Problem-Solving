class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> dist(n, INT_MAX);
        for(auto &v : flights)
            adj[v[0]].push_back({v[1], v[2]});
        queue<vector<int>> q;
        q.push({0, src, 0});
        dist[src] = 0; 
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            int currPrice = current[0];
            int currSrc = current[1];
            int currK = current[2];    
            if (currK > k) continue;
            for (auto neig : adj[currSrc]) {
                int neiNode = neig.first;
                int neiPrice = neig.second;
                if (currK <= k && currPrice + neiPrice < dist[neiNode]) {
                    q.push({currPrice + neiPrice, neiNode, currK + 1});
                    dist[neiNode] = currPrice + neiPrice;
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        int par[n], ans = INT_MAX;
        queue<int> q;
        vector<int> dist;
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0; i<n; i++){
            dist = vector<int>(n, INT_MAX);
            memset(par, -1, sizeof(par));
            dist[i] = 0;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int child : graph[node]){
                    if(dist[child] == INT_MAX){
                        dist[child] = dist[node] + 1;
                        par[child] = node;
                        q.push(child);
                    }
                    else if(par[child] != node && par[node] != child){
                        ans = min(ans, dist[child] + dist[node] + 1);

                    }
                        
                }
            }
        }
        return ans != INT_MAX ? ans : -1;
    }
};
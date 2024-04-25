class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj[n];
        int m=edges.size();
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double wt=succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start_node});
        vector<double>distance(n+1,0.0);
        distance[start_node]=1.0;
        while(!pq.empty()){
            double pro=pq.top().first;
            int  node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                double wt=pro*it.second;
                if(wt>distance[it.first])
                {
                    distance[it.first]=wt;
                    pq.push({wt,it.first});
                }
            }
        }
        if(distance[end_node]==INT_MIN)
            return 0.00000;
        else 
            return distance[end_node];
    }
};
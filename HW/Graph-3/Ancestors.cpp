class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        set<int> st[n];
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto child: adj[node]){
                st[child].insert(node);
                for(auto parent: st[node]){
                    st[child].insert(parent);
                }
                indegree[child]--;
                if(indegree[child] == 0){
                    q.push(child);
                }
            }
        }
        vector<vector<int>> ans(n, vector<int>());
        for(int i=0;i<n;i++){
            ans[i] = vector<int>(st[i].begin(), st[i].end());
        }
        return ans;
    }
};
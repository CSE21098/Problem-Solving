class Solution {
public:
    bool isCycleDfs(int node,unordered_map<int, list<int> > &adj,
         unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited){
        visited[node] = true;
        dfsvisited[node] = true;
        for(auto nbr : adj[node]){
            if(!visited[nbr]){
                bool ans = isCycleDfs(nbr, adj, visited, dfsvisited);
                if(!ans){
                    return false;
                }
            }    
            else if(dfsvisited[nbr]){
                return false;
            }
        
        }
        dfsvisited[node] = false;
        return true; 
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int> > adj;
        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsvisited;

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                bool ans = isCycleDfs(i, adj, visited, dfsvisited);
                if(!ans){
                    return false;
                }
            }
        }
        return true;
    }
};
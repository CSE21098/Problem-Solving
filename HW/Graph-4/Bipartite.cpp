class Solution {
public:
    bool check(vector<vector<int>>& graph, int start,int col,vector<int> &vis){
        vis[start]=col;
        for(auto it : graph[start]){
            if(vis[it]==-1){
                if(!check(graph,it,!col,vis))
                return false;
            }
            else if(vis[it]==vis[start])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
                if(vis[i]==-1){
                if(!check(graph,i,0,vis))
                    return false;
                }   
        }
        return true;
    }
};
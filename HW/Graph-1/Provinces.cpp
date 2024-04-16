class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int src, unordered_map<int, bool>&visited){
        visited[src]=true;
        int n= isConnected[src].size();
        for(int i=0; i<n; i++){
            if(isConnected[src][i] && !visited[i]){
                dfs(isConnected, i, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        int cnt=0;
        unordered_map<int, bool>visited;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                cnt++;
                dfs(isConnected, i, visited);
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        queue<int>q;
        int n=colors.size();
        unordered_map<int,vector<int>> adj;
        vector<int>indegree(n,0);
        vector<vector<int>> memo(n,vector<int>(26,0));
        for(auto i:edges){
            int u=i[0];
            int v= i[1];

            adj[u].push_back(v);
            indegree[v]++;
        }
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                memo[i][colors[i]-'a'] = 1;
            }
        }
        int out=0;
        int cntNodes=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            cntNodes++;
            out= max(out,memo[u][colors[u]-'a']);
            for(auto v :adj[u]){
                for(int i=0;i<26;i++){
                    memo[v][i]=max(memo[v][i] , memo[u][i]+(colors[v]-'a'==i));
                }
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        if(cntNodes<n) return -1;
        return out;
    }
};
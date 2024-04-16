class Solution {
  public:
    bool dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfv,vector<int> adj[]){
        visited[node] = true;
        dfv[node] = true;
        for(auto i:adj[node]){
            if(!visited[i]){
                bool ans = dfs(i,visited,dfv,adj);
                if(ans){
                    return ans;
                }
            }
            else if(dfv[i]){
                return true;
            }
        }
        dfv[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V);
        for(int i=0;i<V ;i++){
            for(auto j:adj[i])
               indegree[j]++;
        }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    int count=0;
	    vector<int> ans;
	    while(!q.empty()){
	        int front= q.front();
	        q.pop();
	        ans.push_back(front);
	        count++;
	        for(auto i: adj[front]){
	            indegree[i]--;
	            if(indegree[i]==0){
	                q.push(i);
	            }
	        }
	    }
	    if(count==V){
	        return false;
	    }
	    return true;
    }
};
class Solution
{   
    void dfs(int node,vector<int> &visited,stack<int> &st,vector<vector<int>>& adj){
        visited[node] = true;
        for(auto i: adj[node]){
            if(!visited[i]){
                dfs(i,visited,st,adj);
            }
        }
        st.push(node);
    }
	public:
	void rdfs(int node,vector<int> &visited,vector<vector<int>> &adj){
	    visited[node] = true;
	    for(auto i: adj[node]){
	        if(!visited[i]){
	            rdfs(i,visited,adj);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> st;
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,st,adj);
            }
        }
        
        vector<vector<int>> transpose(V);
        for(int i=0;i<V;i++){
            visited[i] = 0;
            for(auto j: adj[i]){
                transpose[j].push_back(i);
            }
        }
        int count=0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            if(!visited[top]){
                count++;
                rdfs(top,visited,transpose);
            }
        }
        return count;
    }
};
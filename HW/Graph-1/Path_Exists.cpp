class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)  
    {
        unordered_map<int, vector<int>> um;
        for(auto x:edges){
            um[x[0]].push_back(x[1]);
            um[x[1]].push_back(x[0]); 
        }
        vector<bool> vd(n+1,false);
        queue<int>q;
        q.push(source);
        vd[source]=true;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            vector<int> temp=um[v];
            for(int i=0;i<temp.size();i++){
                int vertex=temp[i];
                if(vd[vertex]==false)
                {
                    q.push(vertex);
                    vd[vertex]=true;
                }
            }
        }
        return vd[destination];
    }
};
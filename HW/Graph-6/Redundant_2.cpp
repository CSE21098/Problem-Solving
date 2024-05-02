class Solution {
public:
int getparent(int src, vector <int> &parent)
{
    if(parent[src]==src)
    return src;
    return parent[src] = getparent(parent[src],parent);
}
bool topopossible(vector<vector<int>>& edges, int j)
{int n=edges.size();
    vector <int> adj[n];
    vector <int> indegree(n,0);
    int x=0;
    for(auto p:edges)
    {if(x!=j){
        adj[p[0]-1].push_back(p[1]-1);
        indegree[p[1]-1]++;
    }
        x++;
    }
    queue <int> q;
    for(int i=0;i<n;i++)
    if(indegree[i]==0)
    q.push(i);
    while(!q.empty())
    {
        for(auto p:adj[q.front()])
        {
            q.push(p);
            indegree[p]--;
            if(indegree[p]==0)
            q.push(p);
        }
        q.pop();
    }
    return *max_element(indegree.begin(),indegree.end()) ==0;
}
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector <int> indegree(n,0);
        for(auto p:edges)
        indegree[p[1]-1]++;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==2) {
                for(int j=n-1;j>=0;j--)
                if(edges[j][1]-1==i)
                {if(topopossible(edges,j))
                return edges[j];}
            }
        }
        vector <int> parent(n);
        for(int i=0;i<n;i++)
        parent[i]=i;
        for(auto p:edges)
        {
            int spx = getparent(p[0]-1,parent);
            int spy = getparent(p[1]-1,parent);
            if(spx==spy)
            return p;
            parent[spy]=spx;
        }
        return {};
    }
};
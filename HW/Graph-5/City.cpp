class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n,vector<int>(n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            int from=edges[i][0];
            int to=edges[i][1];
            int cost=edges[i][2];
            adj[to][from]=cost;
            adj[from][to]=cost;
        }
        for(int i=0;i<n;i++){
            adj[i][i]=0;
        }
        vector<vector<int>> dist=adj;
        for(int v=0;v<n;v++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][v]!=INT_MAX && dist[v][j]!=INT_MAX)
                    dist[i][j]=min(dist[i][j],dist[i][v]+dist[v][j]);
                }
            }
        }
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<dist[i][j]<<" ";
                }
                cout<<endl;
        }
        int cityMax=n+1;
        int city=-1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold) count++;
            }
            if(count<cityMax){ 
                cityMax=count;
                city=i;
            }
            else if(count==cityMax){
                city=max(i,city);
            } 
        }
        return city;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        queue<pair<pair<int,int>, int>>q;
        int visited[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){ 
                    q.push({{i,j},0 }); 
                    visited[i][j]=2;  
                }
                else{
                    visited[i][j]=0;
                }
            }
        }

        int t=0;
        int dx[] = {-1, 0 ,1 ,0};
        int dy[]=  {0, 1, 0, -1 };
        while(!q.empty()){
            int r= q.front().first.first;
            int c= q.front().first.second;
            int time=q.front().second;
            q.pop();
            t=max(t, time);
            for(int i=0; i<4; i++){
                int newR= r+dx[i];
                int newC= c+dy[i];

                if(newR>=0 && newR<n && newC>=0 && newC<m && visited[newR][newC]!=2 && grid[newR][newC]==1){
                    q.push({{newR, newC}, time+1});
                    visited[newR][newC]=2;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && visited[i][j] != 2)
                    return -1;
                
            }
        }
        return t;
    }
};
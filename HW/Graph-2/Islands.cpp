class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited;
        for(int i=0;i<grid.size();i++){
            vector<bool> toPush;
            for(int j=0;j<grid[0].size();j++){
                toPush.push_back(false);
            }
            visited.push_back(toPush);
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                queue<pair<int,int>> bfs;
                bfs.push(make_pair(i,j));
                visited[i][j] = true;
                while(!bfs.empty()){
                pair<int,int> top_element = bfs.front();
                int row = top_element.first;
                int col = top_element.second;
                if((row-1)>=0 && !visited[row-1][col] && grid[row-1][col]=='1'){
                    bfs.push(make_pair(row-1,col));
                    visited[row-1][col] = true;
                }
                if((row+1)<m && !visited[row+1][col] && grid[row+1][col]=='1'){
                        bfs.push(make_pair(row+1,col));
                        visited[row+1][col] = true;
                }
                if((col-1)>=0 && !visited[row][col-1] && grid[row][col-1]=='1'){
                        bfs.push(make_pair(row,col-1));
                        visited[row][col-1] = true;
                }
                if((col+1)<n && !visited[row][col+1] && grid[row][col+1]=='1'){
                    bfs.push(make_pair(row,col+1));
                    visited[row][col+1] = true;
                }
                bfs.pop();
                }
                ans+=1;
                }
                else{
                visited[i][j] = true;
                }
            }
        }
        return ans;
    }  
};
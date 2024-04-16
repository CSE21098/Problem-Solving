class Solution {
public:
    bool dfs(vector<vector<int>>& grid,vector<vector<bool>>&visited, int row, int col)
    {
        if(visited[row][col]){
            return false;
        }
        visited[row][col]=true;
        if(row==grid.size()-1 && col==grid[0].size()-1)
            return true;
        bool ans = false;
        if(grid[row][col]==1)
        {
            if(col+1<grid[0].size())
            {
                if(grid[row][col+1]==1||grid[row][col+1]==3||grid[row][col+1]==5)
                {
                    ans = ans||dfs(grid,visited,row,col+1);
                }
            }
            if(col-1>=0)
            {
                if(grid[row][col-1]==1||grid[row][col-1]==4||grid[row][col-1]==6)
                {
                    ans = ans||dfs(grid,visited,row,col-1);
                }
            }
        }
        else if(grid[row][col]==2)
        {
            if(row+1<grid.size())
            {
                if(grid[row+1][col]==2||grid[row+1][col]==5||grid[row+1][col]==6)
                {
                    ans = ans||dfs(grid,visited,row+1,col);
                }
            }
            if(row-1>=0)
            {
                if(grid[row-1][col]==2||grid[row-1][col]==3||grid[row-1][col]==4)
                {
                    ans = ans||dfs(grid,visited,row-1,col);
                }
            }
        }
        else if(grid[row][col]==3)
        {
            if(row+1<grid.size())
            {
                if(grid[row+1][col]==2||grid[row+1][col]==5||grid[row+1][col]==6)
                {
                    ans = ans||dfs(grid,visited,row+1,col);
                }
            }
            if(col-1>=0)
            {
                if(grid[row][col-1]==1||grid[row][col-1]==4||grid[row][col-1]==6)
                {
                    ans = ans||dfs(grid,visited,row,col-1);
                }
            }
        }
        else if(grid[row][col]==4)
        {
            if(row+1<grid.size())
            {
                if(grid[row+1][col]==2||grid[row+1][col]==5||grid[row+1][col]==6)
                {
                    ans = ans||dfs(grid,visited,row+1,col);
                }
            }
            if(col+1<grid[0].size())
            {
                if(grid[row][col+1]==1||grid[row][col+1]==3||grid[row][col+1]==5)
                {
                    ans = ans||dfs(grid,visited,row,col+1);
                }
            }
        }
        else if(grid[row][col]==5)
        {
            if(col-1>=0)
            {
                if(grid[row][col-1]==1||grid[row][col-1]==4||grid[row][col-1]==6)
                {
                    ans = ans||dfs(grid,visited,row,col-1);
                }
            }
            if(row-1>=0)
            {
                if(grid[row-1][col]==2||grid[row-1][col]==3||grid[row-1][col]==4)
                {
                    ans = ans||dfs(grid,visited,row-1,col);
                }
            }
        }
        else
        {
            if(col+1<grid[0].size())
            {
                if(grid[row][col+1]==1||grid[row][col+1]==3||grid[row][col+1]==5)
                {
                    ans = ans||dfs(grid,visited,row,col+1);
                }
            }
            if(row-1>=0)
            {
                if(grid[row-1][col]==2||grid[row-1][col]==3||grid[row-1][col]==4)
                {
                    ans = ans||dfs(grid,visited,row-1,col);
                }
            }
        }
        return ans;
    }
    bool hasValidPath(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        return dfs(grid,visited,0,0);
    }
};
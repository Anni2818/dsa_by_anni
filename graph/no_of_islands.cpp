// a very good implementation of dfs problem.

class Solution {
  public:
  
    void dfs(vector<vector<char>>& grid,int r,int c,vector<vector<bool>>&vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        if(r<0 || c<0 || r>=n || c>=m) return;
        if(vis[r][c] || grid[r][c] == 'W') return;
        
        vis[r][c] = true;
        
        // 8 directions
        int dr[8] = {-1,-1,-1,0,0,1,1,1};
        int dc[8] = {-1,0,1,-1,1,-1,0,1};
        
        for(int k=0;k<8;k++){
            dfs(grid,r+dr[k],c+dc[k],vis);
        }
    }
  
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='L'){ // only start DFS if it's land
                    dfs(grid,i,j,vis);
                    count++;
                }
            }
        }
        return count;
    }
};

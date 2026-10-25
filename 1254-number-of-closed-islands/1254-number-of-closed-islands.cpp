class Solution {
private:
    void dfs(int sr,int sc,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<int>&delrow,vector<int>&delcol){
        int n=grid.size();
        int m=grid[0].size();
        vis[sr][sc] = 1;
        for(int i=0;i<4;i++){
            int nr = sr + delrow[i];
            int nc = sc + delcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==0){
                dfs(nr,nc,grid,vis,delrow,delcol);
            }
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        vector<int>delrow = {-1,0,+1,0};
        vector<int>delcol = {0,+1,0,-1};
        
        //left - right border
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==0) dfs(i,0,grid,vis,delrow,delcol);
            if(!vis[i][m-1] && grid[i][m-1]==0) dfs(i,m-1,grid,vis,delrow,delcol);
        }

        //top-bottom border
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==0) dfs(0,j,grid,vis,delrow,delcol);
            if(!vis[n-1][j] && grid[n-1][j]==0) dfs(n-1,j,grid,vis,delrow,delcol);
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    if(!vis[i][j]){
                         dfs(i,j,grid,vis,delrow,delcol);  
                         cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};
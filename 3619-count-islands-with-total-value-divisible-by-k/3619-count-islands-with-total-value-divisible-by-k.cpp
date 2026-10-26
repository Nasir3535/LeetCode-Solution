class Solution {
private:
    void dfs(int sr,int sc,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<int>&delrow,vector<int>&delcol,long long& sum){
        int n=grid.size();
        int m=grid[0].size();
        vis[sr][sc] = 1;

        for(int i=0;i<4;i++){
            int nr = sr + delrow[i];
            int nc = sc + delcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]){
                sum += grid[nr][nc];
                
                dfs(nr,nc,grid,vis,delrow,delcol,sum);
            }
        }
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        vector<int>delrow = {-1,0,+1,0};
        vector<int>delcol = {0,+1,0,-1};
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j]){
                    long long sum=grid[i][j];
                    vis[i][j] = 1;
                    dfs(i,j,grid,vis,delrow,delcol,sum);
                    cnt += (sum%k==0);
                }
            }
        }
        return cnt;
    }
};
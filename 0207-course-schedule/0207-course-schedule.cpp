class Solution {
public:
    bool cycle(int node,vector<int>adj[],vector<int>&vis,vector<int>&pathvis){ // cycle detcetion
        vis[node] = 1;
        pathvis[node] = 1;

        for(auto it:adj[node]){
            if(!vis[it]){
                if(cycle(it,adj,vis,pathvis) == 1) return 1;
            }
            else if(pathvis[it])    return 1;
            
        }

        pathvis[node] = 0;
        return 0;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //adj list 
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size() ;i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }    

        vector<int>vis(numCourses);
        vector<int>pathvis(numCourses);

        for(int i=0 ;i<numCourses; i++){
            if(!vis[i]){
                if(cycle(i,adj,vis,pathvis) == 1) return 0;
            }
        }

        return 1;
    }
};
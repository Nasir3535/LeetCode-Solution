class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {    //toposort( bfs-Kahn's Algo)
        //adj list 
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size() ;i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }    

        vector<int>indeg(numCourses);
        for(int i=0 ;i<numCourses; i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }

        queue<int>q;
        for(int i=0 ;i<numCourses; i++){
            if(indeg[i]==0) q.push(i);
        }

        vector<int>toposort;
        while(q.size()){
            int node = q.front();
            q.pop();
            toposort.push_back(node);

            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }

        return toposort.size() == numCourses;
        
    }
};
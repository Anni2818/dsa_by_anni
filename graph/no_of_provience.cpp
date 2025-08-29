//no of times the traversal is performed = no of proviences.

class Solution {
public:

    void dfs(int i,vector<vector<int>>&adj,vector<bool>&vis)
    {
        vis[i] = true;
        for (int j = 0; j < adj[i].size(); j++) {
            if (adj[i][j] == 1 && !vis[j]) 
            {
                dfs(j, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>vis(isConnected.size(),false);
        int count=0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(!vis[i]){
                count++;
                dfs(i,isConnected,vis);
            }
        }
        return count;
    }
};
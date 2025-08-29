//got a standard solution for dfs
//i need to understand it though.. :<

class Solution {
  public:
  
    vector<int> solve(vector<vector<int>>& adj,int i,vector<bool>&vis,vector<int>&ans)
    {
        vis[i]=1;
        ans.push_back(i);
        for(int nbr:adj[i])
        {
            if(!vis[nbr]){
                solve(adj,nbr,vis,ans);
            }
        }
        return ans;
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<bool>vis(adj.size(),false);
        vector<int>ans;
        return solve(adj,0,vis,ans);
    }
};
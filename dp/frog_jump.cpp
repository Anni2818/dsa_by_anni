//this is gfg question
// here we treat n as the index of the height vector.
// just understand why we create 2 ans and return min and how do we return the ans is also imp

class Solution {
  public:
  
    int helper(int n,vector<int>&dp,vector<int>& ht)
    {
        if(n == 0) return 0;
        if(n == 1) return abs(ht[1]-ht[0]);
        if(dp[n]!= -1) return dp[n];
        int ans1 = abs(ht[n]-ht[n-1])+ helper(n-1,dp,ht);
        int ans2 = abs(ht[n]-ht[n-2])+ helper(n-2,dp,ht);
        dp[n] = min(ans2,ans1);
        return dp[n];
    }
  
    int minCost(vector<int>& height) {
        // Code here
        vector<int>dp(height.size(),-1);
        return helper(height.size()-1,dp,height);
    }
};
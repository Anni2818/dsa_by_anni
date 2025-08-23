//this is follow up of the frog jump problem
//just added the for loop which does the job
// happy to implement on my own


class Solution {
public:

    int helper(int n,vector<int>&dp,vector<int>ht,int k)
    {
        if(n == 0) return 0;
        if(n == 1) return abs(ht[1]-ht[0]);
        if(dp[n] != -1) return dp[n];
        int ans= INT_MAX;
        for(int i=1;i<=k;i++)
        {
            int a1 = abs(ht[n]-ht[n-i]) + helper(n-i,dp,ht,k);
            ans = min(a1,ans);
        }
        dp[n] = ans;
        return ans;
    }

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int>dp(n,-1);
        return helper(n-1,dp,heights,k);
    }
};

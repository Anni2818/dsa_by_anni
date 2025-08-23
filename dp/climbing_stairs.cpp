//this is the start of dp solving just read the condition and just do it

class Solution {
public:

    int memo(int n,vector<int>& dp)
    {
        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        if(dp[n] != -1) return dp[n];
        dp[n] = memo(n-1,dp) + memo(n-2,dp);
        return dp[n];
    }

    int tabu(int n)
    {
        vector<int>dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<n+1; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    int climbStairs(int n) {
        //base
        // vector<int>dp(n+1,-1);
        // int res = memo(n,dp);
        int res = tabu(n);
        return res;
    }
};
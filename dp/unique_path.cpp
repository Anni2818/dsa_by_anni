//concentrate man
//not able to solve already solved????

class Solution {
public:

    int solve(vector<vector<int>>&dp,int r,int c,int m,int n)
    {
        if(r>=m || c>= n) return 0;
        if(r == m-1 && c == n-1) return 1;
        if(dp[r][c] != -1) return dp[r][c];

        int ans1 = solve(dp,r+1,c,m,n) + solve(dp,r,c+1,m,n); 

        return dp[r][c] =ans1;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(dp,0,0,m,n);
    }
};
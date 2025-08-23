//we create a 2d dp
// dp[i][k] == can we make it to the end while we are on the ith step and the last jump was of k unit.
// we write here:
// 1. if(stones.find(n+k)) , if(stones.find(n+k-1)) , if(stones.find(n+k+1)) then compute recursion for those
//if nothing is true then dp[n][k] = false;

class Solution {
public:

    unordered_map<int,int>mp;

    bool helper(int i,int lj,vector<vector<int>>&dp,vector<int>&stones)
    {
        //base case
        if(i == stones.size()-1) return true;
        if(dp[i][lj] != -1) return dp[i][lj];

        for(int jumps=lj-1;jumps <= lj+1;jumps++)
        {
            if(jumps <=0) continue;
            //this is the next jump:
            int nj = stones[i] + jumps;
            //now check if it is present in the gien array or not.
            if(mp.count(nj))
            {
                int j = mp[nj];
                //check for recursive function of that stone now:
                if(helper(j,jumps,dp,stones)){
                    dp[i][lj] = 1;
                    return true;
                }
            }
        }
        return dp[i][lj] = 0;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        for(int i=0;i<n;i++) mp[stones[i]] = i;

        return helper(0,0,dp,stones);
    }
};

//please solve this problem thoroghly....
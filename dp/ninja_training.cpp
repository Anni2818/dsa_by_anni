// a very good exercise to practice the core conpcept of the dp

class Solution {
  public:
  
    int helper(vector<vector<int>>&dp,vector<vector<int>>&arr,int last,int day)
    {
        //base case for day 0 => choose max of all three
        if(day ==0){
            int ans=0;
            for(int i=0;i<3;i++)
            {
                if(i!=last){
                    ans = max(arr[day][i],ans);
                }
            }
            dp[day][last] = ans;
            return dp[day][last];
        }
        if(dp[day][last] != -1) return dp[day][last];
        
        //now we should recursively determine the task
        int maxi = 0;
        for(int i=0;i<3;i++)
        {
            if(i!=last)
            {
                maxi = max(maxi, arr[day][i] + helper(dp,arr,i,day-1));
            }
        }
        dp[day][last] = maxi;
        return maxi;
    }
  
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int m = arr.size();
        vector<vector<int>>dp(m,vector<int>(4,-1));
        return helper(dp,arr,3,m-1);
    }
};
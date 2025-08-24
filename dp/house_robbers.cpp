// pretty straight forward question 
// just two cases whether to include or exclude current element.
class Solution {
  public:
  
    int helper(vector<int>&arr,vector<int>&dp,int idx)
    {
        //base case if index is out of bound then we gain zero.
        if(idx>=arr.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        //include the current element
        int ans1 = arr[idx] + helper(arr,dp,idx+2);
        //exlude the current element
        int ans2 = 0 + helper(arr,dp,idx+1);
        
        dp[idx] = max(ans2,ans1);
        return dp[idx];
    }
  
    int findMaxSum(vector<int>& arr) {
        // code here
        vector<int>dp(arr.size()+1,-1);
        return helper(arr,dp,0);
    }
};
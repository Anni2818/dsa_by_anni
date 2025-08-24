class Solution {
public:
    //this helper function signifies what no of steps are required to convert s1(0,i) to s2[0,j].
    int helper(string s1,string s2,int i,int j)
    {
        //base case:
        //if s1 gets exhausted then meaning = convert "" to s2 with j+1 chars
        if(i<0) return j+1; 
        //same for j<0
        if(j<0) return i+1;

        //if we get similar char at i and j
        if(s1[i] == s2[j]) return 0 + helper(s1,s2,i-1,j-1);

        //insert the char. we do not do anything to s1 rather we modify s2 hence only change in j
        int ans1 = 1+ helper(s1,s2,i,j-1);
        //deleting : here we delete the character at i no change in s2 hence only change in i
        int ans2 = 1+ helper(s1,s2,i-1,j);
        //replacing : here we replace the i with char at j hence we change both i and jj with replacement
        int ans3 = 1+ helper(s1,s2,i-1,j-1);

        return min(ans1,min(ans2,ans3));
    }

    int helper(string s1,string s2,int i,int j,vector<vector<int>>&dp)
    {
        //base case:
        //if s1 gets exhausted then meaning = convert "" to s2 with j+1 chars
        if(i<0) return j+1;
        //same for j<0
        if(j<0) return i+1;
        if(dp[i][j]!= -1) return dp[i][j];

        //if we get similar char at i and j
        if(s1[i] == s2[j]){
            // dp[i][j] = helper(s1,s2,i-1,j-1,dp);
            return 0 + helper(s1,s2,i-1,j-1,dp);
        }

        //insert the char. we do not do anything to s1 rather we modify s2 hence only change in j
        int ans1 = 1+ helper(s1,s2,i,j-1,dp);
        //deleting : here we delete the character at i no change in s2 hence only change in i
        int ans2 = 1+ helper(s1,s2,i-1,j,dp);
        //replacing : here we replace the i with char at j hence we change both i and jj with replacement
        int ans3 = 1+ helper(s1,s2,i-1,j-1,dp);

        int ans = min(ans1,min(ans2,ans3));
        dp[i][j] = ans;
        return ans;
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return helper(word1,word2,word1.size()-1,word2.size()-1,dp);
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

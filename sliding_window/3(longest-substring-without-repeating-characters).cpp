//brute force
//basic approach by creating every sub string possible 
//only optimisation is that we stop iteration when already existing char is encountered

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r=0,l=0,maxlen=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            int hash[256] = {0};
            
            for(int j=i;j<n;j++)
            {
                // hash[s[i]] = 1;
                if(hash[s[j]] == 1){
                    break;
                }
                maxlen = max(maxlen,j-i+1);
                hash[s[j]]= 1;
            }
        }
        return maxlen;
    }
};


//sliding window approach
//more optimised

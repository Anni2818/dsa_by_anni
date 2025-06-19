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
//here we consider the shortet window and gradually chaeck for the repeating char
// if we have repeating char then erase it from the set untill the leftmost is unique
// this is inspired from the neetcode yt channel
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>st;
        int l=0,maxlen=0;

        for(int i=0;i<s.size();i++)
        {
            while(st.find(s[i]) != st.end())
            {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[i]);
            maxlen = max(maxlen,i-l+1);
        }
        return maxlen;
    }
};

//tc1:
// a:4,b:2, c:1
// |freq(word[i]) - freq(word[j])| <= k this means that there shiold be a range of freq.
// let min freq be stdf then any char freq can be in range [stdf,stdf+k]
// if f <stdf ==> remove that char entirely
// else       ==> remove f-stdf-k chars

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>mp;
        vector<int>count;
        for(char c: word)
        {
            mp[c]++;
        }
        for(auto &i: mp)
        {
            count.push_back(i.second);
        }
        sort(count.begin(),count.end());
        int mindel = word.size();
        for(int i=0;i<count.size();i++)
        {
            int stdf = count[i];
            int del =0;

            for(int j=0;j<count.size();j++)
            {
                if(count[j] < stdf){ del += count[j];}
                else  if(count[j] > stdf + k) {del += count[j]-(stdf+k);}
            }
            mindel = min(mindel,del);
        }
        return mindel;
    }
};
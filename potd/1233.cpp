//long time no see github 
//solving this problem with ease

class Solution {
public:

    bool startwith(string root,string child)
    {
        if(root.size() > child.size()) return false;
        for(int i=0;i<root.size();i++)
        {
            if(root[i]!= child[i]) return false;
            if(child[root.size()] != '/') return false;
        }
        return true;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>ans;
        ans.push_back(folder[0]);
        string curr=ans[0];
        for(int i=1;i<folder.size();i++)
        {
            if(startwith(ans.back(),folder[i])) continue;
            else ans.push_back(folder[i]);
        }
        return ans;
    }
};
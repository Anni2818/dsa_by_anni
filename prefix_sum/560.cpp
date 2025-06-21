//here we try to use prefix sum variable instead of the vector
//this optimises everything
// we use map alongside the prefix sum
// we see if the psum-k is already present in the map if yes then we directly compute the value


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int psum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            psum += nums[i];
            if(mp.find(psum-k) != mp.end())
            {
                count+= mp[psum-k];
            }
            if(psum == k) count++;
            mp[psum]++;
        }
        return count;
    }
};
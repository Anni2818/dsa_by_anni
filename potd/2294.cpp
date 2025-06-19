// You are given an integer array nums and an integer k. You may partition nums into one or more subsequences such that each element in nums appears in exactly one of the subsequences.
// Return the minimum number of subsequences needed such that the difference between the maximum and minimum values in each subsequence is at most k.
// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

// here i just sorted the array and iterated over it 
// where i will keep the first element with more diff (at every iteration) as reff
// if diff is >k then count++ and change the reff element to current element


class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int diff=0,ref=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            diff = nums[i]-nums[ref];
            if(diff > k){
                count++;
                ref = i;
            } 
        }
        count++;
        return count;
    }
};
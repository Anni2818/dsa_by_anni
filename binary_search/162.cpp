
//this is brute force
// we just iterate over the array and check the neighbouring elements
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if((i==0 || nums[i-1]<nums[i]) && (i==nums.size()-1 || nums[i] > nums[i+1]))
            {
                return i;
            }
        }
        return -1;
    }
};


//this is optimised solution with O(logn) complexity using binary search
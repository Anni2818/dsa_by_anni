//this is the case :
//  finding element in sorted rotated array
// if nums[mid] > nums[low] => element present at left side
// else => present at right side

//pick up the sorted part, store the min and get rid of the other part


class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int mid,ans=INT_MAX;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            //left osrted
            if(nums[mid]>= nums[low]) 
            {
                ans = min(ans,nums[low]);
                low = mid+1;
            }
            //right sorted
            else{
                ans = min(ans,nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};
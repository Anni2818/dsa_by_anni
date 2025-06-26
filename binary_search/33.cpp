//check whether which half of the mid is sorted by checking for this condition: 
//      nums[low] > nums[mid] => left half is unsorted


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        int mid=0;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;

            //if left sorted
            if(nums[low] <= nums[mid])
            {
                //check if the value lies in that half
                if(nums[low]<=target && target <= nums[mid])
                {
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            //if right sorted
            else{
                if(nums[mid]<=target && target <= nums[high])
                {
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};
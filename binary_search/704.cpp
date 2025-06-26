
//the recursive solution
class Solution {
public:

    int bsearch(vector<int>&nums,int s,int e,int target)
    {
        if(s>e) return -1;
        int mid = s+(e-s)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) return bsearch(nums,s,mid-1,target);
        else return bsearch(nums,mid+1,e,target);
    }

    int search(vector<int>& nums, int target) {
        return bsearch(nums,0,nums.size()-1,target);
    }
};


//the iterative solution :
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;  // Corrected boundary, should be size() - 1

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return -1;  // Target not found
    }
};
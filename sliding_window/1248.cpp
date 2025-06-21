//this is a very nice approach similar to 930 
// here we need to find sub arrays with k no of odd numbers 
// we maintain a variable prfix where we increment the ans if we reach the count k
// if we have k doo no and we are not getting any more odd then we just increase the prefix 
// one at a time and add it to ans after looping 

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0, r = 0, count = 0, ans = 0, prefix = 0;
        while (r < nums.size()) {
            if (nums[r] % 2 == 1) {
                count++;
                prefix = 0;
            }
            while (count == k) {
                prefix++;
                if (nums[l] % 2 == 1) count--;
                l++;
            }
            ans += prefix;
            r++;
        }
        return ans;
    }
};
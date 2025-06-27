// the best capacity you can have is the sumation of all the weights
// the least capacity you must have is the max(weights).

// a good observation leads to finding of the range over which you can iterate

class Solution {
public:

    int daysNum(vector<int>nums, int k)
    {
        int days = 1;
        int curr_load=0;
        for(int i:nums)
        {
            if(curr_load +i> k) {
                days++;
                // avery subtle detail to rest curr_load to i not 0
                // setting it to 0 skips the current element;
                curr_load =i;
            }
            else{
                curr_load += i;
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // sort(weights.begin(),weights.end());
        int n = weights.size();
        int maxi = *max_element(weights.begin(),weights.end());
        int l=maxi,h = accumulate(weights.begin(),weights.end(),0);
        int ans=h,mid;

        while(l<=h)
        {
            mid = l+(h-l)/2;
            if(daysNum(weights,mid) <= days)
            {
                ans = min(ans,mid);
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
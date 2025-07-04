// just start putting cows for a fixed min distance
//      if you can place all cows then move to next minval


//this is the first of its kind in this collection

class Solution {
  public:
  
    bool helper(vector<int>& stalls, int k, int minDist) {
        int count = 1;
        int lastPos = stalls[0];
        
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= minDist) {
                count++;
                lastPos = stalls[i];
            }
            if (count == k) return true;
        }
        
        return false;
    }


    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int l = 1, h = stalls.back() - stalls.front();
        int ans = 1;
    
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (helper(stalls, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        
        return ans;
    }

};
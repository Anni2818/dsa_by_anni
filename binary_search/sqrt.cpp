//a good example for use of binary search
//just know that sqrt of a num is always < half of it.

//also check for int overflow use LL

class Solution {
public:
    int floorSqrt(int n) {
        if (n == 0 || n == 1) return n;
        int l = 1, h = n / 2, mid, ans = 0;
        while (l <= h) {
            mid = l + (h - l) / 2;
            if (1LL * mid * mid == n) return mid;
            if (1LL * mid * mid < n) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};

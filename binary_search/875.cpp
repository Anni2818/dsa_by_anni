//we have to minimize the k value
// range for the k value can be from 1 to max(piles)
// for every value of k find the time taken if it fits the condition then try to minimise it

class Solution {
public:
    int timeTaken(vector<int>& piles, long long k) {
        long long time = 0;
        for (int bananas : piles) {
            time += (bananas + k - 1) / k; // ceiling division
            if (time > 1e9) return time; // early exit if time exceeds h
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long time = timeTaken(piles, mid);

            if (time <= h) {
                ans = (int)mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

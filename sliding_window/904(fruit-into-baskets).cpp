//here is the mid optimised solution : 

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0, maxlen = 0;
        unordered_map<int, int> mp;

        while (r < fruits.size()) {
            mp[fruits[r]]++;  // Add the current fruit to the map

            while (mp.size() > 2) {
                mp[fruits[l]]--;  // Shrink the window from the left
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);  // Remove fruit type if its count is zero
                }
                l++;
            }

            maxlen = max(maxlen, r - l + 1);  // Update max length
            r++;
        }

        return maxlen;
    }
};

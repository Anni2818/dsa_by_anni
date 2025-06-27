// another example that observations can make problem solving a very easy job :
//iterate over the array
// as you move forward, the possiblity of ans is k++;
// because at each iteration curr element takes up one missing elemtns space

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int i: arr)
        {
            if(i > k) return k;
            else k++;
        }
        return k;
    }
};
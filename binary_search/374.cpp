/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:

    int bsearch(int s,int e)
    {
        if(s>e) return -1;
        int mid = s+(e-s)/2;
        if(guess(mid) == 0) return mid;
        else if(guess(mid) == 1) return bsearch(mid+1,e);
        else return bsearch(s,mid-1);
    } 

    int guessNumber(int n) {
        return bsearch(1,n);
    }
};
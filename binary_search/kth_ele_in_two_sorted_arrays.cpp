//just maintain a count variable
//when count == k then return the element you just picked up
//but while doing this yu are dealing with already incremented i so take care of it


class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int i=0,j=0;
        int count=0;
        while(i<a.size() && j<b.size() && count!= k)
        {
            if(a[i]<b[j]){
                i++;
                count++;
                if(count == k) return a[i-1];
            }
            else{
                j++;
                count++;
                if(count == k) return b[j-1];
            }
        }
        while(i<a.size() && count!=k){
            i++;
            count++;
            if(count == k) return a[i-1];
        }
        while(j<b.size() && count!=k){
            j++;
            count++;
            if(count == k) return b[j-1];
        }
        return -1;
        
    }
};
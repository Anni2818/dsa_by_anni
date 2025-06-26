// a very out of the box thinking to avoid the complexity of uing to shift the ll's
// study about the limits and ranges given in the problms to avoid such conflicts 
// curated approach where you have to know about when the limit exceeds

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        //Step-1: Keep all set bits until value exceeds k
        long long val = 0;
        int i=0;
        while(i<min(n,32)){
            if(s[n-i-1]=='1'){
                long long power = pow(2,i);
                if(val + power > k)
                    break;
                val += power;
            }
            i++;
        }
        //Step-2: Count the removed bits
        int removed_count = 0;
        while(i<n){
            if(s[n-i-1]=='1')
                removed_count++;
            i++;
        }
        return n-removed_count;
    }
};


//we remove the msb because they contribute more to the binary number 
// iterate from lsb and keep forming the number as soon as it exceeds the k nite the iterator
// count how many set bits are remaining and the and will be nums,size()-no_of_set_bits

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int power;
        int count = 0;
        long long num=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i] == 1)  power = i-(n-1);
            if(num <=k) num += pow(2,power);
            else{
                if(s[i] == '1') count++;
            }
        }
        return n-count;
    }
};

// a more refined apprach to above for removing the conflicts of range of the num and k
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;
        long long num = 0;
        int bit = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                if (bit < 63 && (num + (1LL << bit)) <= k) {
                    num += (1LL << bit);
                    count++;
                }
            } else {
                count++;
            }
            bit++;
        }
        return count;
    }
};
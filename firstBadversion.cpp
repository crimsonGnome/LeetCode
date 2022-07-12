//https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int helperBadVersion(long start, long end)  {
        long m = (start + end ) / 2;
        //base case
        bool isBad = isBadVersion(m);
        if(isBad && !isBadVersion(m-1)) return m;
        if(isBad){
            return helperBadVersion(start, m -1);
        } else {
            return helperBadVersion(m+1, end);
        }
    }
    int firstBadVersion(int n) { 
      return helperBadVersion(0, n);  
    }
    
    
};
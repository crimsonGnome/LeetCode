//https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        if(n < 3) return n;
        std::vector<int> stairs(3,1);
        stairs[1] =2;
        for(int i = 2; i < n; ++i){
            stairs[2] = stairs[1] + stairs[0];
            stairs[0]= stairs[1];
            stairs[1] = stairs[2];
        }
        return stairs[2];
    }
};
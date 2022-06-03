// https://leetcode.com/problems/maximum-subarray/submissions/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = *nums.begin();
        int currentSum = max;
        for(auto i = nums.begin() + 1; i != nums.end(); ++i){
            currentSum = currentSum + *i;  
            if(currentSum > 0){
                if(currentSum > max) max = currentSum;   
            } else {
                if(*i > max) max = *i; 
                currentSum = 0;  
            }
        }
        return max;
    }
};

// Improved 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = *nums.begin();
        int currentSum = max;
        for(auto i = nums.begin() + 1; i != nums.end(); ++i){
            currentSum = currentSum > 0 ? currentSum : 0;
            currentSum += *i;
            max = std::max(currentSum, max);
        }
        return max;
    }
};
#include <vector>

namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       std::vector<int> answer;
       for(auto i = 0; i < nums.size(); ++i){
           for(auto n = i+1; n < nums.size(); ++n){
            if(nums[i] + nums[n] == target){
                answer.push_back(i);
                answer.push_back(n);
                return answer;
            }
           }
       }
       return answer;
    }
};
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

// Coming back and redoing new problems 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> twosum;
        vector<int> answer;

        for(auto i =0; i < nums.size(); i++){
            auto search = twosum.find(target -nums[i]);
            if(search != twosum.end()){
                answer.push_back(search->second);
                answer.push_back(i);
                return answer;
            } else{
                twosum[nums[i]] = i;
            }
        }
        return answer;
    }
};


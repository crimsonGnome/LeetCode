class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        map.insert({nums[0], 1});
        auto best = map.find(nums[0]);
        for(int i = 1; i < nums.size(); ++i){
            auto canidate = map.find(nums[i]);
            if(canidate != map.end()){
               canidate->second++;
                if(canidate->second > best->second){
                    best = canidate;
                }
            } else {
                 map.insert({nums[i],1});
            }
            
        }
        return best->first;
    }
        
};
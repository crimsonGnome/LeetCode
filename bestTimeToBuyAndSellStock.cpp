// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowestPoint = prices[0];
        int maxProfit = 0;
        
        for(auto i = prices.begin() + 1; i != prices.end(); ++i){
            if(*i < lowestPoint){
                lowestPoint =  *i;
                continue;
            }
            if(maxProfit < (*i - lowestPoint)){
                maxProfit = *i - lowestPoint;
            }
        }
        return maxProfit;
        
    }
};
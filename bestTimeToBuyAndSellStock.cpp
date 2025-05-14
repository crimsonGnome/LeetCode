// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// This is probably faster but less human readable;
// Good way to think about optimization and what we are trying to maximize.
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

int maxProfit(vector<int>& prices) {
        int minimum = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] > prices[i-1]) {
                // increasing slope
                int tempProfit = prices[i] - minimum;
                if (tempProfit < maxProfit) continue;
                maxProfit = tempProfit;
            } else {
                // decreasing slope
                if( minimum < prices[i] ) continue;
                minimum = prices[i]; 
            }
            
        }
        return maxProfit;
        
    }
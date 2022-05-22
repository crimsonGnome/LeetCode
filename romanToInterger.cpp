// https://leetcode.com/problems/roman-to-integer/submissions/
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        for(auto i = 0; i < s.length(); ++i){
            auto next = s[i+1];
            int value;
            switch(s[i]){
                case 'I':
                    value = 1;
                    break;
                case 'V':
                    value = 5;
                    break;
                case 'X':
                    value = 10;
                    break;
                case 'L':
                    value = 50;
                    break;
                case 'C':
                    value = 100;
                    break;
                case 'D':
                    value = 500;
                    break;
                default:
                    value = 1000;
            }
            
            if(s[i]  == 'I' && (next == 'V' || next == 'X' )){
                sum -= value;
            }
            else if(s[i] == 'X' && (next == 'L' || next == 'C')){
                 sum -= value;
                 
            }
            else if(s[i]  == 'C' && (next == 'D' || next == 'M')){
                 sum -= value;
                 
            } else {
                sum += value;
            }
        }
        return sum;
    }
};
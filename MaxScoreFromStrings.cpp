// https://leetcode.com/problems/maximum-score-from-removing-substrings/
// solution timing out
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int bigger =  0;
        int smaller = 0;
        char bgChar;
        char smChar;
        if(x > y) {
            bgChar = 'a';
            smChar = 'b'; 
        } else {
            bgChar = 'b';
            smChar = 'a'; 
        }
        for(auto i = 0; i < s.length(); ++i){
            if(s[i] == bgChar && s[i+1] == smChar){
                s.erase(i,2);
                i -= i > 0 ? 2: 1;
                ++bigger;
            }
        }
        for(auto i = 0; i < s.length(); ++i){
            if(s[i] == smChar && s[i+1] == bgChar){
                s.erase(i,2);
                i -= i > 0 ? 2: 1;
                ++smaller;
            }
        }
        if (x > y ) {
            return bigger*x + smaller*y
        }      
        return bigger*y + smaller*x;
    }
};
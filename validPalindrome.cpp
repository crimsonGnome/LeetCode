// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        string pali = "";
        
        for(int i = 0; i < s.size(); ++i){
            if(std::isalnum(s[i]) != 0){
                pali += std::tolower(s[i]);
            }
          
        }
        int size = pali.size();
        for(int i = size / 2; i > 0; --i){
            if(pali[i -1] != pali[size - i ] ) return false;
        }
        return true;
      
    }
};
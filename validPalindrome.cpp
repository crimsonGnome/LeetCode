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

class Solution {
public:
    bool isPalindrome(string s) {
        // Loop 1 - pretreat
        // strip special characters and ws- I think isAlphaNum() is a fearure

        // Loop 2
        // two pointers begininng and end move to center. 
        // divide size/2 even this will perfectly get half. Odd will leave out cetner 

        // always return true, 
        string alphaString ="";
        for (int i = 0; i < s.size(); i++){
            if (isalnum(s[i])){
                char temp = tolower(s[i]);
                alphaString += temp;
            }
        }
        int alphaSize = alphaString.size();
        // cout << alphaString;
        for (int i = 0; i < alphaSize/ 2; i++) {
            if(alphaString[i] != alphaString[alphaSize -1 -i]){
                return false;
            }
        }
        return true;
    }
};
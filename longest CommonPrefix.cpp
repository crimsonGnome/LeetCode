// https://leetcode.com/problems/longest-common-prefix/submissions/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // creat a answer string
        std::string longest = *strs.begin();
        // loop through vecto
        for(auto words = strs.begin() + 1; words != strs.end(); ++words){
            // Compare the longest to the current substring
            if(longest == words->substr(0, longest.length())){
                continue;
            } else if (longest == ""){
                return longest;
            } else {
                // determine the shortest loop
                auto end = longest.length() > words->length() ? words->length() : longest.length();
                std::string temp;
                // loop throught the word and find the new shortest substring
                for(auto i = 0; i <= end; ++i){
                    auto a1 = longest.substr(0, i);
                    auto a2 = words->substr(0, i); 
                    if(a1 == a2){
                        temp = a1;
                    }
                }
                // return temp
                longest = temp;
               
            }
            
        }
        return longest;
    }
};
// https://leetcode.com/problems/valid-parentheses/submissions/
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stackyStack;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '{' ||  s[i] == '[' || s[i] == '(' ) {
                stackyStack.push(s[i]);
                continue;
            }
            if(stackyStack.empty()) return false;
            if( stackyStack.top() == '{' &&  s[i] == '}'){
                stackyStack.pop();
                continue;
            }
            if( stackyStack.top() == '[' &&  s[i] == ']'){
                stackyStack.pop();
                continue;
            }
            if( stackyStack.top() == '(' &&  s[i] == ')'){
                stackyStack.pop();
                continue;
            }
            return false;
        }
        return stackyStack.empty();
    
    }
};
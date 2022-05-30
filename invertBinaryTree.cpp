=/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}=
 * };
 */
// my solution... 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        std::unordered_map<char, int> letters;
        std::unordered_map<char, int> letters2; 

        for(int i = 0; i < s.size(); ++i){
            letters[s[i]]++;
            letters2[t[i]]++;
        }
        return letters == letters2;
    }
};
// fastest solution
class Solution {
public:
    bool isAnagram(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        if(n != m) return false;
        vector<int> mp(26, 0);
        
        for(int i=0; i<n; i++) {
            mp[str1[i]-'a']++;
            mp[str2[i]-'a']--;
        }
        
        for(int i=0; i<26; i++) {
            if(mp[i] != 0) return false;
        }
        return true;
    }
};
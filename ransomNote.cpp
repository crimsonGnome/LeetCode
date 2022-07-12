// https://leetcode.com/problems/ransom-note/
// My solution which is slower bust still O(n) 
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> note;
        for(int i = 0; i < magazine.size(); ++i){
            if(note.find(magazine[i]) != note.end()){
                note[magazine[i]]++;
            } else {
                note[magazine[i]] = 1;
            }
        }
        for(int j = 0; j < ransomNote.size(); ++j){
            if(note.find(ransomNote[j]) != note.end()){
                note[ransomNote[j]]--;
                if(note[ransomNote[j]] < 0) return false;
            } else {
                return false;
            }
        }
        return true;
        
    }
};

// better solution for RansomNote
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> letter(26, 0);
        for(auto& i: magazine)
        {
            ++letter[i - 'a'];
        }
        for(auto& i: ransomNote)
        {
            --letter[i - 'a'];
            if(letter[i - 'a'] < 0)
                return false;
        }
        return true;
    }
};


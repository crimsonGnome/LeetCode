
//while solution
class Solution {
public:
    class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() -1;
        while(s <= e) {
            int i = s + (e- s)/2;
            if(nums[i] == target) return i;  
            else if (target < nums[i]) e = i - 1;
            else s = i + 1;
            
         }
         return -1;
    }
};



// recursive solution - slower then forloop 
class Solution {
public:
    int searchRec(vector<int>& nums, int& target, int& end, int& start){
        int i = (start + end)/ 2;
        if(nums[i] == target) return i;
        if(start >= end || i ==0) return -1;
        if(target < nums[i]) {
            end = i - 1;
        } else {
            start = i + 1;
        }
        return searchRec(nums, target, end, start);
    }
    int search(vector<int>& nums, int target) {
        int end =nums.size();
        int start = 0;
        return  searchRec(nums, target, end, start);
    }
};
/**
 * https://leetcode.com/problems/diameter-of-binary-tree/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helperRootFinder(TreeNode* root, int& maxValue){
        // base case;
        if(root->left == nullptr && root->right == nullptr) return 0;
        int right = 0;
        int left = 0;
        int canidate = 0;
        if(root->left != nullptr) {
           left = helperRootFinder(root->left, maxValue); 
            canidate += left +1;
        } 
        if(root->right != nullptr){
            right = helperRootFinder(root->right, maxValue);
            canidate += right +1;
        } 8
        if(maxValue < canidate) maxValue = canidate;
        int answer = max(right, left) + 1;
        return answer;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxValue = 0;
        int right = 0;
        int left = 0;
        if(root->left != nullptr) left = helperRootFinder(root->left, maxValue) + 1;
        if(root->right != nullptr) right = helperRootFinder(root->right, maxValue) + 1;
        
        int answer = right + left;
        if(answer > maxValue) return answer;
        return maxValue;
    }

};
/**
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
    int binraryRecurstion(TreeNode* root) {
        if(root == NULL) return -1;
        int left = binraryRecurstion(root->left);
        int right = binraryRecurstion(root->right);
        
        if(left == -2|| right == -2) return -2;
        if( std::abs(left - right) > 1){
            return -2;
        }
        return  std::max(left, right) + 1;

    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int answer = binraryRecurstion(root);
        return answer == -2? false: true;
    }
};
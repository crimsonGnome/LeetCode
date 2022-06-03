// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
        {
            return NULL;
        }
        if(root==p|| root==q)
        {
            return root;
        }
        TreeNode* k1= lowestCommonAncestor(root->left,p, q);
        TreeNode* k2= lowestCommonAncestor(root->right,p,q);
        if(k1!=NULL&&k2!=NULL)
        {
            return root;
        }
        else if(k1!=NULL)
            return k1;
        else
        {
            return k2;
        }
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root->val <= max(p->val,q->val) && root->val >= min(p->val,q->val)){
            return root;
        }
        if(root->val > max(p->val,q->val)){
            return lowestCommonAncestor(root->left,p,q);
        }
        if(root->val < min(p->val,q->val)){
            return lowestCommonAncestor(root->right,p,q);
        }
        return NULL;
    }
};

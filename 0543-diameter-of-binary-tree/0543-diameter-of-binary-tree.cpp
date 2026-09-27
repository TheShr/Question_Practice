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

 // The longest path between any two nodes !
 
class Solution {
public:
    int maxD = 0;
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int left = height(root->left);
        int right = height(root->right);
        maxD = max(maxD, left+right);
        return 1+max(left,right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxD;
    }
};
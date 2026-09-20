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
    int heightL(TreeNode* root){
        if(root == NULL) return 0;
        TreeNode* node = root;
        int height = 0;
        while(node){
            height++;
            node = node-> left;
        }
        return height;
    }
    int heightR(TreeNode* root){
        if(root == NULL) return 0;
        TreeNode* node = root;
        int height = 0;
        while(node){
            height++;
            node = node-> right;
        }
        return height;
    }

    int func(TreeNode* root){
        if(root == NULL) return 0;

        int leftH = heightL(root);
        int rightH = heightR(root);

        if(rightH == leftH) {
            return (1<<leftH) - 1;
        }

        return 1 + func(root->left) + func(root->right);;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return func(root);
    }
};
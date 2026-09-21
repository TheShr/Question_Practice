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
    bool flag = true;
    long long prev = LLONG_MIN;
    void func(TreeNode* root){
        if(root == NULL) return;
        
        func(root->left);
        if(root->val <= prev){
            flag = false;
            return;
        }
        prev = root->val;
        func(root->right);
        

        
    }
    bool isValidBST(TreeNode* root) {
        func(root);
        return flag;
    }
};
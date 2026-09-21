/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}


1 3 4 2

mx = 
mn = 
 * };
 */
class Solution {
public:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    void func(TreeNode* root){
        if(root == NULL) return;

        func(root->left);
        if(prev != NULL && prev->val > root->val){
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else last = root;
        }

        prev = root;
        func(root->right);

    }
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        TreeNode* prev = new TreeNode(INT_MIN);

        func(root);
        if(first && last) swap(first->val, last->val);
        else if(first && !last) swap(first->val, middle->val);
    }
};
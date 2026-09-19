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
    vector<TreeNode*> a, b;
    bool func(TreeNode* root, TreeNode* node, vector<TreeNode*> &v){
        if(root ==NULL) return false;

        v.push_back(root);
        if(root == node) return true;
        if(func(root->left, node,v) ||
            func(root->right, node, v)) {
            return true;
        }

        v.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        a.clear();b.clear();

        if(!func(root, p, a) || !func(root, q, b)) return NULL;
        
        TreeNode* lca = NULL;
        for(int i= 0; i<a.size() && i < b.size(); i++){
            if(a[i] != b[i]) break;
            lca = a[i];
                
            
        }

        return lca;
    }
};
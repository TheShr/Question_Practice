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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        
        queue<pair<TreeNode*, long long>> q;
        q.push({root ,0});
        while(!q.empty()){
            int size = q.size();
            int minidx = q.front().second;
            int st = 0, end = 0;
            for(int i = 0; i< size; i++){
                auto top = q.front();
                TreeNode* node = top.first;
                long long x = top.second - minidx;
                q.pop();
                if(i == 0) st = x;
                if(i == size-1) end = x;

                if(node->left != NULL) q.push({node->left, 2*x + 1});
                if(node->right != NULL) q.push({node->right, 2*x+ 2});
                //x++;
            }
            ans = max(ans, end-st+1);
        }

        return ans;
    }
};
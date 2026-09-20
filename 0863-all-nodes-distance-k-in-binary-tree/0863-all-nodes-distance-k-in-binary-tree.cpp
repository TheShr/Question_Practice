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
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right] = node;
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // we can convert tree to graph by adding son to parent traversal feature
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);
        if(root == NULL) return {};
        
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> vis;
        q.push(target);
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            vis[target] = true;
            if(level++ == k) break;
            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if(parent[node] && !vis[parent[node]]){
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            ans.push_back(top->val);
        }

        return ans;
    }
};
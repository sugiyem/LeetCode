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
    bool isCompleteTree(TreeNode* root) {
        bool end = false;
        queue<TreeNode*> vis;
        vis.push(root);
        while(!vis.empty()) {
            TreeNode* curr = vis.front();
            vis.pop();
            if (curr == NULL) {
                end = true;
            } else {
                if (end) {
                    return false;
                }
                vis.push(curr -> left);
                vis.push(curr -> right);
            }
        }
        return true;
    }
};
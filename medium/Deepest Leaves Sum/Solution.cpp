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
    int deepestLeavesSum(TreeNode* root) {
        vector<TreeNode*> vis;
        int ans;
        vis.push_back(root);
        while(vis.size()) {
            ans = 0;
            vector<TreeNode*> newVis;
            for (TreeNode* u : vis) {
                ans += u -> val;
                if (u -> left != NULL) {
                    newVis.push_back(u -> left);
                }
                if (u -> right != NULL) {
                    newVis.push_back(u -> right);
                }
            }
            vis = newVis;
        }
        return ans;
        
    }
    
};
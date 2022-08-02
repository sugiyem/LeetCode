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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == subRoot) {
            return true;
        }
        
        if (root == NULL || subRoot == NULL) {
            return false;
        }
        
        
        getHeightAndAddToTrees(getHeightAndAddToTrees(-1, subRoot), root);
        
        for (TreeNode* tree : trees) {
            if (isEqual(subRoot, tree)) {
                return true;
            }
        }
        
        return false;
    }
private:
    vector<TreeNode*> trees;
    
    int getHeightAndAddToTrees(int targetHeight, TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int ans = 1 + max(getHeightAndAddToTrees(targetHeight, root -> left),
                     getHeightAndAddToTrees(targetHeight, root -> right));
        
        if (ans == targetHeight) {
            trees.push_back(root);
        }
        
        return ans;
    }
    
    bool isEqual(TreeNode* first, TreeNode* second) {
        if (first == second) {
            return true;
        }
        
        if (first == NULL || second == NULL || first -> val != second -> val) {
            return false;
        }
        
        return isEqual(first -> left, second -> left) && 
            isEqual(first -> right, second -> right);
    }
};
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
    bool isValidBST(TreeNode* root) {
        long long currMax = -2147483649;
        return isValid(root, &currMax);
    }
private:
    bool isValid(TreeNode* tree, long long *currMax) {
        if (tree == NULL) {
            return true;
        } else if (!isValid(tree -> left, currMax)) {
            return false;
        } else if (tree -> val <= *currMax) {
            return false;
        }
        
        *currMax = tree -> val;
        return isValid(tree -> right, currMax);
        
    }
};
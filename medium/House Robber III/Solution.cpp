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
    int rob(TreeNode* root) {
        int robbed = 0, notRobbed = 0;
        return binaryRob(root, robbed, notRobbed);
    }
private:
    int binaryRob(TreeNode* root, int& robbed, int& notRobbed) {
        if (root == NULL) return 0;
        int leftRobbed = 0, leftNotRobbed = 0, rightRobbed = 0, rightNotRobbed = 0;
        int left = binaryRob(root -> left, leftRobbed, leftNotRobbed);
        int right = binaryRob(root -> right, rightRobbed, rightNotRobbed);
        
        robbed = root -> val + leftNotRobbed + rightNotRobbed;
        notRobbed = left + right;
        return max(robbed, notRobbed);
    }
};
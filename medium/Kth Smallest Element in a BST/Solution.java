/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int findWeight(TreeNode root, HashMap<TreeNode, Integer> weights) {
        if (root == null) {
            return 0;
        }
        
        int ans = 1 + findWeight(root.left, weights) + findWeight(root.right, weights);
        weights.put(root, ans);
        return ans;
    }
    
    public int kthSmallest(TreeNode root, int k) {
        HashMap<TreeNode, Integer> weights = new HashMap<>();
        weights.put(null, 0);
        findWeight(root, weights);
        return kthSmallest(root, k, weights);
    }
    
    public int kthSmallest(TreeNode root, int k, HashMap<TreeNode, Integer> weights) {
        int x = weights.get(root.left) + 1;
        if (k < x) {
            return kthSmallest(root.left, k, weights);
        } else if (k > x) {
            return kthSmallest(root.right, k - x, weights);
        } else {
            return root.val;
        }
    }
}
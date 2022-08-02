/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
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
    private ListNode list;
    public TreeNode sortedListToBST(ListNode head) {
        ListNode curr = head;
        int num = 0;
        this.list = head;
        while(curr != null) {
            ++num;
            curr = curr.next;
        }
        return helper(0, num - 1);
    }
    private TreeNode helper(int start, int end) {
        if (start > end) {
            return null;
        }
        int mid = start + (end - start) / 2;
        TreeNode left = helper(start, mid - 1);
        TreeNode ans = new TreeNode(this.list.val);
        this.list = this.list.next;
        TreeNode right = helper(mid + 1, end);
        ans.left = left;
        ans.right = right;
        return ans;
    }
}
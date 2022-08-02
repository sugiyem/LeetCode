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
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null || l2 == null) {
            return l1 == null ? l2 : l1;
        }
        
        int sum = l1.val + l2.val;
        if (sum < 10) {
            ListNode ans = new ListNode(sum, addTwoNumbers(l1.next, l2.next));
            return ans;
        }
        else {
            ListNode one = new ListNode(1);
            ListNode ans = new ListNode(sum % 10, 
                addTwoNumbers(addTwoNumbers(one, l1.next), l2.next));
            return ans;
        }
    }
}
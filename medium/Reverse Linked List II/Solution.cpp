/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* pre = dummy;
        for (int i = 0; i < left - 1; ++i) {
            pre = pre -> next;
        }
        ListNode* curr = pre -> next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* then = pre -> next;
            pre -> next = curr -> next;
            curr -> next = curr -> next -> next;
            pre -> next -> next = then;
        }
        return dummy -> next;
        
        
        
    }
};
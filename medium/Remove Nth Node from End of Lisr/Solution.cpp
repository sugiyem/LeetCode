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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *firstPointer = head, *secondPointer = head;
        
        for (int i = 0; i < n; i++) {
            firstPointer = firstPointer -> next;
        }
        
        if (firstPointer == NULL) {
            return head -> next;
        }
        
        while (firstPointer -> next != NULL) {
            firstPointer = firstPointer -> next;
            secondPointer = secondPointer -> next;
        }
        
        secondPointer -> next = secondPointer -> next -> next;
        return head;
    }
};
/*
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
    ListNode* partition(ListNode* head, int x) {
        ListNode small(0), large(0);
        ListNode *smallPtr = &small, *largePtr = &large;

        while(head) {
            if (head -> val >= x) {
                largePtr -> next = head;
                largePtr = head;
            } else {
                smallPtr -> next = head;
                smallPtr = head;
            }
            
            head = head -> next;
        }
        
        largePtr -> next = NULL;
        smallPtr -> next = large.next;
        return small.next;
    }
};
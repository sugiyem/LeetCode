/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        
        ListNode *firstPointer = headA, *secondPointer = headB;
        while(firstPointer != secondPointer && firstPointer != NULL && secondPointer != NULL) {
            firstPointer = firstPointer -> next;
            secondPointer = secondPointer -> next;
            
            if (firstPointer == secondPointer) {
                break;
            }
            
            if (firstPointer == NULL) {
                firstPointer = headB;
            }
            
            if (secondPointer == NULL) {
                secondPointer = headA;
            }
        }
        
        return firstPointer;
    }
};
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
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        
        ListNode *slowPointer = head, *fastPointer = head;
        
        while(fastPointer && fastPointer -> next) {
            slowPointer = slowPointer -> next;
            fastPointer = fastPointer -> next -> next;
            if (slowPointer == fastPointer) {
                return true;
            }
        }
        
        return false;
    }
};
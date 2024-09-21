//recursive way to reverse single linked list
/*
class Solution {
public:
    ListNode * reverseList(ListNode* &prev, ListNode* &curr) 
    {
        if(curr == NULL) {
            return prev;
        }
        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        return reverseList(prev, curr);
    }
    ListNode * reverseList(ListNode* head) 
    {
        ListNode* prev = NULL;
        ListNode* curr = head;

        ListNode* newHead = reverseList(prev, curr);
        return newHead;
    }
};
*/
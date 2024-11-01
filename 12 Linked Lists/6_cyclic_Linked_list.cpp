//Leetcode 141
/*
class Solution {
public:
    bool check(ListNode* &head)
    {
        ListNode* temp=head;
        ListNode* temp1=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            if(temp!=NULL )
            {
                temp1=temp1->next;
                temp=temp->next;
                if(temp == temp1)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool hasCycle(ListNode *head) {
        bool cool=check(head);
        return cool;
    }
};
*/
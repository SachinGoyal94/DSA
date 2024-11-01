//must see imp points in one note linked list for space complexity
//here time complexity=O(N) space complexity=O(1)
class Solution {
  public:
    void Tailinsert(Node* &head,Node* &tail,Node* &move)
    {
        if(head==NULL && tail==NULL)
        {
            head=move;
            tail=move;
        }
        else
        {
            tail->next=move;
            tail=move;
        }
    }
    Node* segregate(Node* head) 
    {
        Node * zerohead=NULL;
        Node * zerotail=NULL;
        Node * onehead=NULL;
        Node * onetail=NULL;
        Node * twohead=NULL;
        Node * twotail=NULL;
        Node * temp=head;
        while(temp!=NULL)
        {
            Node* tomove=temp;
            temp=temp->next;
            tomove->next=NULL;
            if(tomove->data==0)
            {
                Tailinsert(zerohead,zerotail,tomove);
            }
            else 
            {
                if(tomove->data==1)
                {
                    Tailinsert(onehead,onetail,tomove);
                }
                else
                {
                    if(tomove->data==2)
                    {
                        Tailinsert(twohead,twotail,tomove);
                    }
                }
            }
        }
        if(zerohead!=NULL)
        {
            if(onehead!=NULL)
            {
                zerotail->next=onehead;
                onetail->next=twohead;
            }
            else
            {
                zerotail->next=twohead;
            }
            return zerohead;
        }
        else
        {
            if(onehead!=NULL)
            {
                onetail->next=twohead;
                return onehead;
            }
            else
            {
                return twohead;
            }
        }    
    }
};
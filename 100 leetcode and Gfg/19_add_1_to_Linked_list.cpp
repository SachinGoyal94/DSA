/*
class Solution {
  public:
    Node* reverselist(Node* &head)
    {
        Node* temp=head;
        Node* prev=NULL;
        while(temp!=NULL)
        {
            Node* forward=temp->next;
            temp->next=prev;
            prev=temp;
            temp=forward;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        Node * rh=reverselist(head);
        int add=1;
        Node* rev=rh;
        Node* prevv=NULL;
        while(rh!=NULL)
        {
            int sum=rh->data+add;
            add=(sum)/10;
            rh->data=(sum)%10;
            prevv=rh;
            rh=rh->next;
        }
        if(add==1)
        {
            Node* newn=new Node(1);
            prevv->next=newn;
        }
        Node* result=reverselist(rev);
        return result;
    }
};
*/


/*
class Solution {
  public:
    Node* Tailinsertion(Node* &rev)
    {
        Node* temp=rev;
        while(temp->next!=NULL)
        {
        temp=temp->next;
        }
        Node* te=new Node(1);
        temp->next=te;
        return rev;
    }
    void adder(Node* &revhead)
    {
        Node* temp=revhead;
        int carry=0,add=1;
        while(add==1)
        {
            temp->data=temp->data+1;
            if(temp->data==10)
            {
                temp->data=0;
                carry=1;
                add=1;
            }
            else
            {
                carry=0;
                add=0;
                return;
            }
            if(temp->next==NULL )
            {
                temp=Tailinsertion(revhead);
                return ;
            }
            temp=temp->next;
        }
    }
    Node* reverser(Node * &prev,Node* &head)
    {
        Node* curr=head;
        
        while(curr!=NULL)
        {
            Node* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    Node* addOne(Node* head) 
    {
        Node*temp=head;
        Node * prev=NULL;
        Node* reversed=reverser(prev,temp);
        adder(reversed);
        Node* previous=NULL;
        Node* final=reverser(previous,reversed);
        return final;
    }
};
*/

//must see "next node in one notes"
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node * next;//next stores memory address of object of Node as in linked
    Node(int value)
    {
        data=value;
        next=NULL;    //automatically after creating a node it refers to next node as null until we create one more after it 
    }
};
Node * Headinsertion(int value,Node* &head,Node* &tail)
{
    if(head==NULL && tail==NULL)
    {
        Node* newnode=new Node(value);
        head=newnode;
        tail=newnode;
    }
    else
    {
        Node* newnode=new Node(value);
        newnode->next=head;//here newnode->next means jo nayi node hai vo pichle bni node ke head ko refer kregi coz it's a head insertion
                           //so newnode ka ek pointer (2nd box (chk notes))will refer to head 
        head=newnode;
    }
    return head;
}
Node * Tailinsertion(int value,Node* &head,Node* &tail)
{
    if(head==NULL && tail==NULL)
    {
        Node* newnode=new Node(value);
        head=newnode;
        tail=newnode;
    }
    else
    {
        Node* newnode=new Node(value);
        tail->next=newnode;
        tail=newnode;
    }
    return tail;
}
void print(Node * &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl<<endl;
}
int getlength(Node * &head)
{
    int len=0;
    Node * temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        len++;
    }
    return len;
}
void insertion(int position,int value,Node* &head,Node* &tail)
{
    int len=getlength(head);
    if(position==1)
    {
        head=Headinsertion(value,head,tail);
    }
    else
    {
        if(position==(len+1))
        {
            tail=Tailinsertion(value,head,tail);
        }
        else
        {
            Node * temp=head;
            for(int i=0;i<position-2;i++)
            {
                temp=temp->next;
            }
            Node* newnode=new Node(value);
            newnode->next=temp->next;
            temp->next=newnode;        
        }
    }
}
int SearchLL(int target,Node* &head,Node* &tail)
{
    Node *temp=head;
    int len=1;
    while(temp!=NULL)
    {
        if(target==temp->data)
        {
            return len; 
        }
        else
        {
            temp=temp->next;
            len++;
        }
    }
    return -1;
}
void deletion(int position,Node* &head,Node* &tail)
{
    if(position>getlength(head) || position<1 )
    {
        cout<<"valid index required"<<endl;
        return ;
    }
    if(head==NULL && tail==NULL)
    {
        cout<<"nothing to be deleted"<<endl;
        return ;
    }
    if(head==tail)
    {
        Node *temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
    }
    if(position==1)
    {
        Node * temp=head;
        head=head->next;
        temp->next=NULL;   //isolate the node from rest of the nodes
        delete temp;       //now delete isolated node
        return ;
    }
    Node * temp=head;
    for(int i=0;i<position-2;i++)
    {
        temp=temp->next;
    }
    Node *temp1=temp->next;
    temp->next=temp1->next;
    temp1->next=NULL;
    delete temp1;
}
void deletebyvalue(int value,Node* &head,Node* &tail)
{
    int position=SearchLL(value,head,tail);
    if(position==-1)
    {
        cout<<"deletion by value -> "<<value<<" not found"<<endl;
        return;
    }
    cout<<"deletion by value -> "<<value<<" founded "<<endl;
    deletion(position,head,tail);
}

int main()
{
    Node* head=NULL;         //head is object of Node which is storing address of head node
    Node* tail=NULL;         //tail is object of Node which is storing address of tail node
    
    head=Headinsertion(101,head,tail);
    print(head);
    
    head=Headinsertion(111,head,tail);
    print(head);
    
    head=Headinsertion(121,head,tail);
    print(head);
    
    tail=Tailinsertion(199,head,tail);
    print(head);

    tail=Tailinsertion(189,head,tail);
    print(head);

    tail=Tailinsertion(179,head,tail);
    print(head);

    insertion(1,131,head,tail);
    print(head);
    
    insertion(3,110,head,tail);   //indexing of position starts from 1  add node before 3rd node
    print(head);
    
    cout<<"length = "<<getlength(head)<<endl;
    cout<<"target=110 and founded at position "<<SearchLL(110,head,tail)<<endl;
    cout<<"target=120 and founded at position"<<SearchLL(120,head,tail)<<endl;
    
    deletion(1,head,tail);
    print(head);
    
    deletion(10,head,tail);
    print(head);

    deletion(3,head,tail);
    print(head);

    deletebyvalue(179,head,tail);
    print(head);

    deletebyvalue(11111,head,tail);
    print(head);


    cout<<"FINAL LINKED LIST IS "<<endl;
    print(head);
    
    return 0;
}
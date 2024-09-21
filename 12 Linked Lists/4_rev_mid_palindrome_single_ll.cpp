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
void getmiddle(Node* &head,Node* &mid,Node* &mid_previous)
{
    Node * temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        if(temp!=NULL)
        {
            mid_previous=mid;
            temp=temp->next;
            mid=mid->next;
        }
    }
    return ;
}
Node* reverser(Node * &prev,Node* &curr)
{
    while(curr!=NULL)
    {
        Node*forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
bool ispalindrome(Node* &head,Node* &mid)
{
    //edge cases
    if(head->next==NULL || head==NULL)
    {
        return false;
    }
    Node* temp=head;
    Node* temp1=mid;
    while(temp!=NULL)
    {
        if(temp->data!=temp1->data)
        {
            return false;
        }
        temp=temp->next;
        temp1=temp1->next;
    }
    return true;
}
int main()
{
    Node* head=NULL;         
    Node* tail=NULL;         
    head=Headinsertion(141,head,tail);
    head=Headinsertion(111,head,tail);
    head=Headinsertion(101,head,tail);
    tail=Tailinsertion(111,head,tail);
    tail=Tailinsertion(101,head,tail);
    cout<<"FINAL LINKED LIST IS "<<endl;
    print(head);

    //get middle
    Node* mid=head;
    Node* mid_previous=head;
    getmiddle(head,mid,mid_previous);
    cout<<mid->data<<"   "<<mid_previous->data<<endl;

    //reverse second half
    mid_previous->next=NULL;
    Node* prev=NULL;
    Node* curr=mid;
    Node *secondhalf=reverser(prev,curr);

    //check palindrome
    bool checker=ispalindrome(head,secondhalf);
    cout<<checker;
    return 0;
}

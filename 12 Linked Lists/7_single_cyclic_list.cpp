#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node (int d)
    {
        next=NULL;
        data=d;
    }
};
void Headins(Node* &head,int value)
{
    if(head==NULL )
    {
        Node* newnode=new Node(value);
        newnode->next=newnode;
        head=newnode;
    }
    else
    {
        Node* newnode=new Node(value);
        Node*temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=newnode;
        newnode->next=head;
    }
}
void Tailins(Node* &head,int value)
{
    if(head==NULL)
    {
        Node* newnode=new Node(value);
        newnode->next=newnode;
        head=newnode;
    }
    else
    {
        Node* newnode=new Node(value);
        Node*temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=newnode;
        newnode->next=head;
    }
}
void display(Node* &head)
{
    Node*temp=head;
    cout<<temp->data<<"->";
    temp=temp->next;
    while(temp!=head)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
int getlength(Node* &head)
{
    Node*temp=head;
    int size=0;
    while(temp->next!=head)
    {
        temp=temp->next;
        size++;
    }
    return size;
}
void deletion(Node* &head,int pos)
{
    if(head==NULL)
        return;
    if(pos==1)
    {
        Node*temp=head;
        Node* temptail=head;
        while(temptail->next!=head)
        {
            temptail=temptail->next;
        }
        temptail->next=head->next;
        head=head->next;
        delete temp;
    }
    else
    {
        Node*temp=head;
        for(int i=0;i<pos-2;i++)
        {
            temp=temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
}
bool cycle(Node*&head)
{
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
            if(slow==fast)
                return true;
        }
    }
}
int main()
{
    Node* head=NULL;
    Headins(head,1);
    Headins(head,2);
    Tailins(head,3);
    Tailins(head,4);
    display(head);
    deletion(head,3);
    display(head);
    cout<<"iscycle "<<cycle(head)<<endl;
}
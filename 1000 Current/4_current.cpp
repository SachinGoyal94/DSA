#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *prev;
    Node* next;
    Node(int value)
    {
        data=value;
        prev=NULL;
        next=NULL;
    }
};
Node* HeadInsertion(int value,Node* &head,Node* & tail)
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
        newnode->next=head;//Connecting nodes to each other
        head->prev=newnode;
        head=newnode;
    }
}
Node* TailInsertion(int value,Node* &head,Node* & tail)
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
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
    }
}
void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl<<endl;
}
void printreverse(Node* & tail)
{
    Node* temp=tail;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->prev;
    }
    cout<<"NULL"<<endl<<endl;
}
int getlength(Node* &head)
{
    Node* temp=head;
    int len=0;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    return len;
}
void insertor(int position,int value,Node* &head,Node* & tail)
{
    int len=getlength(head);
    if(position==1)
    {
        HeadInsertion(value,head,tail);
    }
    else
    {
        if(position==(len+1))
        {
            TailInsertion(value,head,tail);
        }
        else
        {
            Node * temp=head;
            for(int i=0;i<position-2;i++)
            {
                temp=temp->next;
            }
            Node* newnode=new Node(value);
            Node * forward=temp->next;
            newnode->prev=temp;
            temp->next=newnode;
            forward->prev=newnode;
            newnode->next=forward;
        }
    }
}
int Searcher(int value,Node * &head,Node* &tail)
{
    Node* temp=head;
    int pos=1;
    while(temp!=NULL)
    {
        if(temp->data==value)
            return pos;
        else
        {
            pos++;
        }
        temp=temp->next;
    }
    return -1;
}
void deleter(int position,Node * &head,Node* &tail)
{
    int len=getlength(head);
    if(head==NULL && tail==NULL)
    {
        cout<<"empty double linked list"<<endl;
        return ;
    }
    if(head==tail)
    {
        Node * temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
    }
    if(position==1)
    {
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        if(position==(len))
        {
            Node* temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            temp->prev=NULL;
            delete temp;
        }
        else
        {
            Node* temp=head;
            for(int i=0;i<position-2;i++)
            {
                temp=temp->next;
            }
            Node* pos=temp->next;
            Node*forward=pos->next;
            temp->next=forward;
            forward->prev=temp;
            pos->prev=NULL;
            pos->next=NULL;
            delete pos;
        }
    }
}
int main()
{
    Node * head=NULL;
    Node * tail=NULL;
    HeadInsertion(100,head,tail);
    print(head);

    HeadInsertion(110,head,tail);
    print(head);

    TailInsertion(111,head,tail);
    print(head);

    TailInsertion(121,head,tail);
    print(head);

    printreverse(tail);
    cout<<getlength(head)<<endl;

    insertor(3,105,head,tail);
    print(head);
    
    insertor(6,131,head,tail);
    print(head);

    insertor(1,120,head,tail);
    print(head);

    cout<<"deleter"<<endl;
    deleter(7,head,tail);
    print(head);

    cout<<Searcher(11,head,tail);
}
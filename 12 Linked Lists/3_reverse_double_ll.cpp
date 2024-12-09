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

Node * reverser(Node * &head,Node* &current,Node* &prev)
{
    Node * forward=current->next;
    current->next=prev;
    prev=current;
    current=forward;
    if(current==NULL)
    {
        head=prev;
        return prev;
    }
    return reverser(head,current,prev);
}
Node * middler(Node* &head)
{
    Node* mid=head;
    Node*temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        if(temp!=NULL)
        {
            temp=temp->next;
            mid=mid->next;
        }
    }
    return mid;
}
bool checkpalindrome(Node* &mid,Node* &midd)
{
    while(mid!=NULL && midd!=NULL)
    {
        if(mid->data!=midd->data)
        {
            return 0;
        }
        mid=mid->prev;
        midd=midd->next;
    }
}
int main()
{
    Node * head=NULL;
    Node * tail=NULL;
    HeadInsertion(150,head,tail);
    print(head);

    HeadInsertion(140,head,tail);
    print(head);

    TailInsertion(160,head,tail);
    print(head);

    TailInsertion(170,head,tail);
    print(head);

    cout<<getlength(head)<<endl;

    insertor(1,130,head,tail);
    print(head);
    
    insertor(6,180,head,tail);
    print(head);

    insertor(1,120,head,tail);
    print(head);
    cout<<"reverser"<<endl;
    Node *temp=head;
    temp->prev=NULL; 
    Node * newhead= reverser(head,temp,temp->prev);
    print(newhead);

    Node* mid=middler(head);
    cout<<"middle value is "<<mid->data<<endl;

    int len=getlength(head);
    cout<<"length = "<<len<<endl;
    print(head);
    if(len%2==0)
    {
        bool checking=checkpalindrome(mid->prev,mid);
        cout<<"is palindrome "<<checking;
    }
    else
    {
        bool checking=checkpalindrome(mid->prev,mid->next);
        cout<<"is palindrome "<<checking<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    int degree;
    Node * next;
    Node(int value,int power)
    {
        data=value;
        degree=power;
        next=NULL;   
    }
};
Node * Headinsertion(int value,int power,Node* &head,Node* &tail)
{
    if(head==NULL && tail==NULL)
    {
        Node* newnode=new Node(value,power);
        head=newnode;
        tail=newnode;
    }
    else
    {
        Node* newnode=new Node(value,power);
        newnode->next=head;
        head=newnode;
    }
    return head;
}
Node * Tailinsertion(int value,int power,Node* &head,Node* &tail)
{
    if(head==NULL && tail==NULL)
    {
        Node* newnode=new Node(value,power);
        head=newnode;
        tail=newnode;
    }
    else
    {
        Node* newnode=new Node(value,power);
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
        cout<<temp->data<<"^"<<temp->degree<<"->";
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
Node* add(Node* &head,Node* &head2,Node*&head3,Node* &tail)
{
    Node*temp1=head;
    Node* temp2=head2;
    Node*sum=head3;
    int size1=getlength(temp1);
    int size2=getlength(temp2);
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->degree==temp2->degree)
        {
            int result=temp1->data+temp2->data;
            Tailinsertion(result,temp1->degree,head3,tail);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else
        {
            if(temp1->degree>temp2->degree)
            {
                Tailinsertion(temp1->data,temp1->degree,head3,tail);
                temp1=temp1->next;
            }
        }
    }
}
int main()
{
    Node* head=NULL;         
    Node* tail=NULL;         

    head=Headinsertion(121,0,head,tail);
    head=Headinsertion(111,1,head,tail);
    head=Headinsertion(101,2,head,tail);
    cout<<"FINAL LINKED LIST IS "<<endl;
    print(head);

    cout<<"linked list 2"<<endl;

    Node* head1=NULL;         
    Node* tail1=NULL;         
    
    head1=Headinsertion(31,0,head1,tail1);
    head1=Headinsertion(21,1,head1,tail1);
    cout<<"FINAL LINKED LIST 2 IS "<<endl;
    print(head1);

    Node* head2=NULL;
    Node*tail2 =NULL;
    add(head,head1,head2,tail2);
    print(head2);
    /*
    INTERSECTION

    Node*temp1=head;
    Node*temp2=head1;
    int len=1;
    int size1=getlength(head);
    int size2=getlength(head1);
    while(temp2!=NULL)
    {
        if(temp1->data==temp2->data)
        {
            cout<<"intersection start from node value "<<temp1->data<<endl;
            break;
        }
        else
        {
            if(size1>size2)
            {
                temp1=temp1->next;
                size1--;
            }
            else
            {
                if(size2>size1)
                {
                    temp2=temp2->next;
                    size2--;
                }
                else
                {
                    temp1=temp1->next;
                    temp2=temp2->next;
                    size1--;
                    size2--;
                }
            }
        }
        
    }
    */
    return 0;
} 
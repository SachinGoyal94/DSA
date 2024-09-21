#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    Node *next,*prev;
    int data;
    Node(int d)
    {
        data=d;
        next=NULL;
        prev=NULL;
    }
};
Node* Headinsertion(Node * &head,Node * &tail,int data)
{
    if(head==NULL && tail == NULL)
    {
        Node * temp=new Node (data);
        head=temp;
        tail=temp;
    }
    else
    {
        Node * temp=new Node(data);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    return head;
}
Node * Tailinsertion(Node * &head,Node * &tail,int data)
{
    if(head==NULL && tail==NULL)
    {
        Node *temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else
    {
        Node* temp=new Node(data);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
    return tail;
}
void print(Node * &head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl<<endl;
}
void reverse_print(Node * &tail)
{
    Node * temp=tail;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->prev;
    }
    cout<<"NULL"<<endl<<endl;
}
int length(Node * &head)
{
    int len=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    return len;
}
void Insertion(Node * &head,Node * &tail,int position,int data)
{
    int len=length(head);
    if(position<1 || position>(len+1))
    {
        cout<<"invalid index"<<endl;
        return ;
    }
    if((position==1))
    {
        Headinsertion(head,tail,data);
    }
    else
    {
        if(position==(len+1))
        {
            Tailinsertion(head,tail,data);
        }
        else
        {
            Node* temp=head;
            for(int i=0;i<position-2;i++)
            {
                temp=temp->next;
            }
            Node * temp1=new Node(data);
            Node * further=temp->next;
            temp1->next=further;
            temp1->prev=temp;
            further->prev=temp1;
            temp->next=temp1;
        }
    }
}
int search(Node* &head,Node * &tail,int data)
{
    int len=length(head);
    int position=1;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            return position;
        }
        else
        {
            position++;
            temp=temp->next;
        }

    }
    return -1;
}
void deleter(Node * &head,Node * &tail,int position)
{
    int len=length(head);
    if(position<1 || position>len)
    {
        cout<<"valid index required"<<endl;
        return;
    }
    if(head==tail)
    {
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
    }
    else
    {
        if(position==1)
        {
            Node*temp=head;
            head=temp->next;
            head->prev=NULL;
            temp->next=NULL;
            delete temp;
        }
        else
        {
            if(position==len)
            {
                Node * temp=tail;
                tail=temp->prev;
                if(tail!=NULL)
                tail->next=NULL;
                temp->prev=NULL;
                delete temp;
            }
            else
            {
                Node *temp=head;
                for(int i=0;i<position-2;i++)
                {
                    temp=temp->next;
                }
                Node * temp1=temp->next;
                Node* further=temp1->next;
                temp->next=further;
                further->prev=temp;
                temp1->prev=NULL;
                temp1->next=NULL;
                delete temp1;
            }
        }
    }
}
void deletebyvalue(Node* &head,Node* &tail,int data)
{
    int position=search(head,tail,data);
    if(position==-1)
    {
        cout<<"value not found"<<endl;
        return;
    }
    deleter(head,tail,position);
}
int main()
{
    Node *head=NULL;
    Node *tail=NULL;
    Headinsertion(head,tail,150);
    print(head);
    Headinsertion(head,tail,140);
    print(head);
    Headinsertion(head,tail,130);
    print(head);
    Tailinsertion(head,tail,160);
    print(head);
    Tailinsertion(head,tail,170);
    print(head);
    Tailinsertion(head,tail,180);
    print(head);
    cout<<"length="<<length(head)<<endl;
    cout<<"searching "<<search(head,tail,180)<<endl;
    Insertion(head,tail,1,120);
    print(head);
    deleter(head,tail,7);
    print(head);
    deletebyvalue(head,tail,170);
    print(head);
    reverse_print(tail);
}
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node * next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};
class myStack
{
    public:
    Node* head;
    int size;
    myStack()
    {
        size=0;
        head=NULL;
    }
    void push(int g)
    {
        Node* temp=new Node(g);
        temp->next=head;
        head=temp;
        size++;
    }
    void pop()
    {
        if(head==NULL)
        {
            cout<<"already empty"<<endl;
            return;
        }
        Node* temp=head;
        head=temp->next;
        temp->next=NULL;
        delete temp;
        size--;
    }
    int top()
    {
        if(head==NULL)
        {
            cout<<"empty stack"<<endl;
            return -1;
        }
        return head->data;
    }
    int getsize()
    {
        return size;
    }
    bool empty()
    {
        if(head==NULL)
        {
            return 1;
        }
        return 0;
    }
};
int main()
{
    myStack s;
    s.push(10);
    cout<<s.getsize()<<endl;
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.push(20);
    s.push(30);
    cout<<s.top();
}

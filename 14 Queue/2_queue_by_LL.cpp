#include <bits/stdc++.h>
using namespace std;
using namespace std;
class Node
{
    public:
    Node* next;
    int data;
    Node(int d)
    {
        next=NULL;
        data=d;
    }
};
class Queue{
  public:
    Node* front;
    Node* back;
    
    Queue() 
    {
        front=NULL;
        back=NULL;
    }        
    
    void push(int val) 
    {
        if(front == NULL && back== NULL) 
        {
            Node* n= new Node(val);
            front=n;
            back=n;
        }
        else 
        {
            Node* newnode=new Node(val);
            back->next=newnode;
            back=newnode;
        }
    }
    void pop() 
    {
        if(front==NULL && back==NULL) {
        cout << "Underflow" << endl;
        }
        else 
        {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
    int getFront() 
    {
        if(front == NULL) 
        {
            cout << "Queue is empty";
            return -1;
        }    
        return front->data;
    }
    bool isEmpty() 
    {
        if(front == NULL && back==NULL) 
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    void print()
    {
        Node* temp=front;
        while(temp!=back)
        {
            cout<<temp->data<<"   ";
            temp=temp->next;
        }
        cout<<temp->data;
        cout<<endl;
    }
};




int main() 
{
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.push(100);
    q.print();
    q.push(101);
    q.print();
    cout << q.isEmpty() << endl;
    cout << q.getFront() << endl;

  return 0;
}
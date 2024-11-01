#include<bits/stdc++.h>
using namespace std;

//Queue using array
class Queue
{
    int *arr;
    int front;
    int rear; 
    int size;
    public:
    Queue(int s)
    {
        size=s;
        front=-1;
        rear=-1;
        arr=new int(s);
    }
    void Enequeue(int d)
    {
        if(rear==size-1)
        {
            cout<<"overflow"<<endl;
            return;
        }
        arr[++rear]=d;
    }
    void Dequeue()
    {
        if(front==rear )
        {
            cout<<"underflow"<<endl;
            return;
        }
        arr[++front]=-1;
    }
    int getfront()
    {
        if( front==rear)
        {
            cout<<"Empty"<<endl;
            return -1;
        }
        if(front==-1)
            return arr[front+1];
        return arr[front+1];
    }
    int getrear()
    {
        if(rear==-1 || front==rear)
        {
            cout<<"Empty"<<endl;
            return -1;
        }
        return arr[rear];
    }
    int getsize()
    {
        if(rear==-1 ||front==rear)
        {
            cout<<"Empty"<<endl;
            return 0;
        }
        return rear-front;
    }
    bool isempty()
    {
        if(rear==-1 ||front==rear)
        {
            return 1;
        }
        return 0;
    }
};
int main()
{
    Queue q(5);
    q.Enequeue(10);
    cout<<q.getfront()<<endl;
    cout<<q.getrear()<<endl;
    cout<<q.getsize()<<endl;
    cout<<q.isempty()<<endl;

    q.Enequeue(20);
    cout<<q.getfront()<<endl;
    cout<<q.getrear()<<endl;
    cout<<q.getsize()<<endl;
    cout<<q.isempty()<<endl;

    q.Enequeue(30);
    cout<<q.getfront()<<endl;
    cout<<q.getrear()<<endl;
    cout<<q.getsize()<<endl;
    cout<<q.isempty()<<endl;

    q.Enequeue(40);
    cout<<q.getfront()<<endl;
    cout<<q.getrear()<<endl;
    cout<<q.getsize()<<endl;
    cout<<q.isempty()<<endl;

    q.Enequeue(50);
    cout<<q.getfront()<<endl;
    cout<<q.getrear()<<endl;
    cout<<q.getsize()<<endl;
    cout<<q.isempty()<<endl;

    q.Enequeue(60);
    cout<<q.getfront()<<endl;
    cout<<q.getrear()<<endl;
    cout<<q.getsize()<<endl;
    cout<<q.isempty()<<endl;
}
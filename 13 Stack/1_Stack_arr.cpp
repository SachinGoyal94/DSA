//implementing stack using array
#include<bits/stdc++.h>
using namespace std;
class Stack
{
    public:
    int top;
    int *arr;
    int size;
    Stack(int s)
    {
        size=s;
        arr=new int(s);
        top=-1;
    }
    void push(int data)
    {
        if(top==size-1)
        {
            cout<<"Stack Overflow"<<endl;
        }
        else
        {
            top++;
            arr[top]=data;
        }
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack underflow"<<endl;
        }
        else
        {
            arr[top]=-1;  //just for understanding during output
            top--;
        }
    }
    bool empty()
    {
        if(top==-1)
        {
            return true;
        }
        return false;
    }
    int getsize()
    {
        return top+1;
    }
    int gettop()
    {
        if(top==-1)
        {
            cout<<"Empty Stack"<<endl;
            return -1;
        }
        return arr[top];
    }
    void print()
    {
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<"    ";
        }
        cout<<endl;
    }
};
int main()
{
    Stack s(5);
    s.push(10);
    s.print();
    cout<<s.gettop()<<endl;

    s.push(20);
    s.print();
    cout<<s.gettop()<<endl;

    s.push(30);
    s.print();
    cout<<s.gettop()<<endl;

    s.push(40);
    s.print();
    cout<<s.gettop()<<endl;

    s.push(50);
    s.print();
    cout<<s.gettop()<<endl;

    cout<<s.getsize()<<endl;
    cout<<s.empty()<<endl;

    s.pop();
    s.print();
    cout<<s.gettop()<<endl;

    s.pop();
    s.print();
    cout<<s.gettop()<<endl;

    s.pop();
    s.print();
    cout<<s.gettop()<<endl;

    s.pop();
    s.print();
    cout<<s.gettop()<<endl;

    s.pop();
    s.print();
    cout<<s.gettop()<<endl;

    s.pop();
    s.print();
    cout<<s.gettop()<<endl;

    cout<<s.getsize()<<endl;
}
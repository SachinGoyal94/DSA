#include<bits/stdc++.h>
using namespace std;
class Stack
{
    public:
    int top1,top2,size;
    int *arr;
    Stack(int n)
    {
        size=n;
        arr=new int(n);
        top1=-1;
        top2=n;
    }
    void push1(int data)
    {
        if(top2-top1==1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else
        {
            top1++;
            arr[top1]=data;
        }
    }
    void push2(int data)
    {
        if(top2-top1==1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else
        {
            top2--;
            arr[top2]=data;
        }
    }
    void pop1()
    {
        if(top1==-1)
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        else
        {
            arr[top1]=-1;
            top1--;
        }
    }
    void pop2()
    {
        if(top2==size)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else
        {
            arr[top2]=-1;
            top2++;
        }
    }
    void print()
    {
        cout<<"printing"<<endl;
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<"   ";
        }
        cout<<endl;
    }
    int getsize()
    {
        if(top1==-1 && top2==size)
        {
            return 0;
        }
        else
        {
            if(top1==-1)
            {
                return size-top2;
            }
            else
            {
                if(top2==size)
                {
                    return top1+1;
                }
                else
                    return size-top2+top1+1;
            }
        }
    }
    bool empty()
    {
        cout<<"isempty ?? ";
        if(getsize()==0)
            return 1;
        return 0;
    }
};
int main()
{
    Stack s(8);
    s.print();
    cout<<s.empty()<<endl;

    s.push1(10);
    s.print();
    cout<<s.getsize()<<endl;
    s.push1(20);
    s.print();
    cout<<s.getsize()<<endl;

    s.push1(30);
    s.print();
    cout<<s.getsize()<<endl;

    s.push2(80);
    s.print();
    cout<<s.getsize()<<endl;
    s.push2(70);
    s.print();
    cout<<s.getsize()<<endl;

    s.push2(60);
    s.print();
    cout<<s.getsize()<<endl;

    s.push2(50);
    s.print();
    cout<<s.getsize()<<endl;
    s.push2(40);
    s.print();
    cout<<s.getsize()<<endl;
    
    s.push2(1000);
    s.print();
    cout<<s.getsize()<<endl;
    
    cout<<s.empty()<<endl;

}
//rest functions are same or just modify a little bit 
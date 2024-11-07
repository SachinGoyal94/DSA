#include<bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    //Time complexities
    //push O(N)  pop O(1)   top O(1)    emptyO(1)
    stack<int>s1,s2;
    MyQueue() 
    {}
    void push(int x) 
    {
        
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        } 
    }
    int pop() 
    {
        int x=s1.top();
        s1.pop();
        return x;
    }
    
    int peek() 
    {
        return s1.top();    
    }
    
    bool empty() 
    {
        if(s1.empty())
            return 1;
        return 0;    
    }
};
/*
class MyQueue {
public:
    //Time complexities
    //push O(1)  pop O(N)   top O(N)    emptyO(1)
    stack<int>s1,s2;
    MyQueue() 
    {}
    void push(int x) 
    {
        s1.push(x); 
    }
    int pop() 
    {
        int pop=-1;
        if(!s2.empty())
            pop=s2.top();
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            pop=s2.top();
        }
        s2.pop();
        return pop;
    }
    
    int peek() 
    {
        int top=-1;
        if(!s2.empty())
            top=s2.top();
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            top=s2.top();
        }
        return top;   
    }
    
    bool empty() 
    {
        return s1.empty() && s2.empty();    
    }
};
*/
int main()
{
    MyQueue m;
    m.push(10);
    m.push(20);
    cout<<m.peek();
}

#include<bits/stdc++.h>
using namespace std;
class MyStack 
{
public:
    queue<int>q;
    MyStack() 
    {    
    }
    //using 1queue
    //push O(N)   pop,top,empty O(1)
    void push(int x) 
    {
        q.push(x);
        for(int i=0;i<q.size()-1;i++)
        {
            int front=q.front();
            q.pop();
            q.push(front);
        }
    }
    int pop() 
    {
        int pop=q.front();
        q.pop();
        return pop;   
    }
    
    int top() 
    {
        return q.front();    
    }
    
    bool empty() 
    {
        return q.empty();
    }
};
class MyStack 
{
public:
    queue<int>q1,q2;
    MyStack() 
    {    
    }
    //push O(N)   pop,top,empty O(1)
    void push(int x) 
    {
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }    
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    int pop() 
    {
        int pop=q1.front();
        q1.pop();
        return pop;   
    }
    
    int top() 
    {
        return q1.front();    
    }
    
    bool empty() 
    {
        return q1.empty();
    }
};
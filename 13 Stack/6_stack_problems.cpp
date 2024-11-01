#include<bits/stdc++.h>
using namespace std;
void insertatbottom(stack<int> &s,int value)
{
    if(s.empty())
    {
        s.push(value);
        return;
    }
    int topelement=s.top();
    s.pop();
    insertatbottom(s,value);
    s.push(topelement);
    return;
}
bool sorted(stack<int> &s,int value)
{
    if(s.empty())
        return true;
    bool checck;
    if(value>s.top())
    {
        int element=s.top();
        s.pop();
        checck=sorted(s,element);
        s.push(element);
    }
    else
    {
        return false;
    }
    return checck;
}
void reversestack(stack<int>& s)
{
    if(s.empty())
        return;
    int value=s.top();
    s.pop();
    reversestack(s);
    insertatbottom(s,value);
}
void sortedinsert(stack<int>&s,int value)
{
    if(s.empty())
    {
        s.push(value);
        return;
    }
    if(s.top()>value)
    {
        int topelement=s.top();
        s.pop();
        sortedinsert(s,value);
        s.push(topelement);
    }
    else
    {
        s.push(value);
        return ;
    }
}
int main()
{
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    //insertatbottom(s,9);
    // int value=INT_MAX;
    // bool checkk=sorted(s,value);
    // cout<<checkk;
    // reversestack(s);
    sortedinsert(s,61);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    
}
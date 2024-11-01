#include<bits/stdc++.h>
using namespace std;
int getsize(stack<int>s)
{
    int len=0;
    while(!s.empty())
    {
        len++;
        s.pop();
    }
    return len;
}
int findmid(stack<int>s,int len,int cnt)
{
    if(cnt==len)
    {
        return s.top();
    }
    int val=s.top();
    s.pop();
    cnt++;
    int result=findmid(s,len,cnt);
    s.push(val);
    return result;
}
int checksorted(stack<int>s,int chk)
{
    if(s.empty())
        return 1;
    int checkkk=0;
    if(s.top()<chk)
    {
        int val=s.top();
        s.pop();
        checkkk=checksorted(s,val);
    }
    else
    {
        return checkkk;
    }
    return checkkk;
}
void insertatbottom(stack<int>&s,int val)
{
    if(s.empty())
    {
        s.push(val);
        return;
    }
    int value=s.top();
    s.pop();
    insertatbottom(s,val);
    s.push(value);
    return;
}
void reverser(stack<int>&s)
{
    if(s.empty())
        return;
    int val=s.top();
    s.pop();
    reverser(s);
    insertatbottom(s,val);
    return;
}
void sortedinsert(stack<int>&s,int val)
{
    if(s.empty())
    {
        s.push(val);
        return;
    }
    if(val<s.top())
    {
        int value=s.top();
        s.pop();
        sortedinsert(s,val);
        s.push(value);
        return;
    }
    else
    {
        s.push(val);
        return;
    }
}
int main()
{
    stack<int>s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);
    // s.push(60);
    // // int len=getsize(s);
    // int cnt=0;
    // cout<<len<<endl;
    // int result=findmid(s,(len/2),cnt);
    // cout<<result<<endl;
    // cout<<len<<endl;
    // cout<<checksorted(s,INT_MAX)<<endl;
    // insertatbottom(s,9);
    // reverser(s);
    //sortedinsert(s,11);
    int i=4;
    while(i--)
    {
        if(i==1)
        {
            continue;
        }
        cout<<"yeah"<<i<<endl;

    }
    cout<<endl;
}
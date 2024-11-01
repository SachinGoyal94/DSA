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
int main()
{
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    insertatbottom(s,9);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}
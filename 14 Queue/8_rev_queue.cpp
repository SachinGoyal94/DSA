#include<bits/stdc++.h>
using namespace std;
void printer(queue<int>q)
{
    while(!q.empty())
    {
        cout<<q.front()<<"    ";
        q.pop();
    }
    cout<<endl;
}
void reverser(queue<int>&q)
{
    stack<int>st;
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}
void reverseink(queue<int>&q,int k,int upto,int n)
{
    stack<int>st;
    for(int i=0;i<upto;i++)
    {
        for(int j=0;j<k;j++)
        {
            st.push(q.front());
            q.pop();
        }
        for(int j=0;j<k;j++)
        {
            q.push(st.top());
            st.pop();
        }
    }
    int left=n-(k*upto);
    while(left--)
    {
        int e=q.front();
        q.push(e);
        q.pop();
    }
}
int main()
{
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    printer(q);
    // reverser(q);
    // printer(q);

    // int k=3;
    // int n=q.size();
    // int find=n/k;
    // reverseink(q,k,find,n);
    // printer(q);
}
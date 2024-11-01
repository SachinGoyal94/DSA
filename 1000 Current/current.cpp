#include <bits/stdc++.h>
using namespace std;
int chkred(stack<char>&s)
{
    int opcount=0;
    while(s.top()!='(')
    {
        char ch=s.top();
        if(ch=='+' ||ch=='-' ||ch=='/' ||ch=='*')
        {
            opcount++;
        }
        s.pop();
    }
    s.pop();
    if(opcount>0)
    {
        return 0;
    }
    return 1;
}
int main()
{
    // int str[5]={8,4,6,2,3};
    // stack<int>s;
    // vector<int>ans;
    // s.push(-1);
    // for(int i=0;i<=4;i++)
    // {
    //     while(s.top()>str[i])
    //     {
    //         s.pop();
    //     }
    //     ans.push_back(s.top());
    //     s.push(str[i]);        
    // }
    // for(int i=0;i<5;i++)
    // {
    //     cout<<ans[i]<<"    ";
    // }
    int b=1<<3;
    cout<<b;
}
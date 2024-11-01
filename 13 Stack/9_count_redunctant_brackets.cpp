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
    stack<char>s;
    string str="(3+(5)+6*((7)))";   //(5)=1   ((7))=2 total 3 red.()
    int redun=0;
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        if(ch==')')
        {
            int chk=chkred(s);
            if(chk==1)
            {
                redun++;
            }
        }
        else
            s.push(ch);
    }
    cout<<redun;
}
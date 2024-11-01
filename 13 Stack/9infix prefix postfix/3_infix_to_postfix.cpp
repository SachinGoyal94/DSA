#include<bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if(c=='^')
        return 3;
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    else
        return 0;
}

string topost(string s)
{
    stack<char> st;
    string ans="";
    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        if(c=='(')
        {
            st.push(c);
        }
        else if(c==')')
        {
            while(st.top()!='(')
            {
                ans.push_back(st.top());
                st.pop();
            }
            st.pop(); // remove the '('
        }
        else if(c=='+' || c=='-' || c=='*' || c=='/' ||c=='^')
        {
            while(!st.empty() && st.top()!='(' && precedence(c) <= precedence(st.top()))
            {
                ans.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
        else//letters
        {
            ans.push_back(c);
        }
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    string s="(A+(B^(C-D)/E))";  
    string ans=topost(s);
    cout<<ans<<endl;
    return 0;
}
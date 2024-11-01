//Leetcode 20
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="({[]})";   //true
    string k="({())})";  //false
    string m="({)}()";   //false
    stack<char>st;
    for(int i=0;i<s.size();i++)
    {
        char ch=s[i];
        if(ch=='(' || ch=='{' || ch=='[')
        {
            st.push(ch);
        }
        else
        {
            if(ch==')' && !st.empty() && st.top()=='(')
            {
                cout<<"true";
                return 0;
            }
            else
            {
                if(ch=='}' && !st.empty() && st.top()=='{')
                {
                    cout<<"true";
                    return 0;
                }   
                else
                {
                    if(ch==']' && !st.empty() && st.top()=='[')
                    {
                        cout<<"true";
                        return 0;
                    }
                    else
                    {
                        cout<<"false";
                        return 0;
                    }
                }
            }
        }
    }
}
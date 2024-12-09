//Leetcode 20
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="({[]})";   //true
    string k="({())})";  //false
    string m="({)}()";   //false
    stack<char>st;
    for(int i=0;i<k.size();i++)
    {
        char ch=k[i];
        if(ch=='(' || ch=='{' || ch=='[')
        {
            st.push(ch);
        }
        else
        {
            if(ch==')' && !st.empty() && st.top()=='(')
            {
                cout<<"true";
            }
            else
            {
                if(ch=='}' && !st.empty() && st.top()=='{')
                {
                    cout<<"true";
                }   
                else
                {
                    if(ch==']' && !st.empty() && st.top()=='[')
                    {
                        cout<<"true";
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
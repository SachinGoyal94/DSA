#include<bits/stdc++.h>
using namespace std;
int postfixeval(string s)
{
    stack<int>st;
    for(int i=0;i<=s.length()-1;i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else
        {
            int op2=st.top();
            st.pop();
            int op1=st.top();
            st.pop();
            switch(s[i])
            {
                case '+':
                    st.push(op1+op2);
                    break;
                case '-':
                    st.push(op1-op2);
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
                case '^':
                    st.push(pow(op1,op2));
                    break;
            }
        }
    }
    return st.top();
}
int main()
{
    string s="223^+7*5-";
    cout<<postfixeval(s);
}
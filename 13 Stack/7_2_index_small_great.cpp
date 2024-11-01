#include<bits/stdc++.h>
using namespace std;
vector<int> nextgreater(int arr[],int n)
{
    stack<int>st;
    st.push(-1);
    vector<int>ans;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && st.top()!=-1 && arr[st.top()] <= arr[i])
        {
            st.pop();
        }
        ans.push_back(st.top());
        st.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
vector<int> prevgreater(int arr[],int n)
{
    stack<int>st;
    st.push(-1);
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top()!=-1 && arr[st.top()] <= arr[i])
        {
            st.pop();
        }
        ans.push_back(st.top());
        st.push(i);
    }
    return ans;
}
vector<int> nextsmaller(int arr[],int n)
{
    stack<int>st;
    st.push(-1);
    vector<int>ans;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && st.top()!=-1 && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        ans.push_back(st.top());
        st.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
vector<int> prevsmaller(int arr[],int n)
{
    stack<int>st;
    st.push(-1);
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top()!=-1 && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        ans.push_back(st.top());
        st.push(i);
    }
    return ans;
}
int main()
{
    int arr[5]={8,8,6,2,3};
    int n=5;
    vector<int> ans = nextgreater(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<"   ";
    }
}
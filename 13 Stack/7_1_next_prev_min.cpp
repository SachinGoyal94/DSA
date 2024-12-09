#include <bits/stdc++.h>
using namespace std;

void nextSmallerElement(int arr[], int n, vector<int>& ans) 
{
  stack<int> s;
  s.push(-1);

  for(int i=n-1; i>=0; i-- ) 
  {
    int element = arr[i];
    while(s.top() >= element) 
    {
        s.pop();
    }
    ans.push_back(s.top());
    s.push(element);
  }
  reverse(ans.begin(),ans.end());
}

void prevSmallerElement(int arr[], int n, vector<int>& ans) 
{
    stack<int> s;
    s.push(-1);
    for(int i=0; i<n; i++) 
    {
        int element = arr[i];
        while(s.top() >= element) 
        {
        s.pop();
        }
        ans.push_back(s.top());
        s.push(arr[i]);
    }
}
void nextgreaterelement(int arr[],int n,vector<int>&ans)
{
    stack<int> s;
    s.push(-1);
    for(int i=n-1;i>=0;i--)
    {
      while(s.top()!=-1 && s.top()<=arr[i])
      {
        s.pop();
      }
      ans.push_back(s.top());
      s.push(arr[i]);
    }
  reverse(ans.begin(),ans.end());
}
void prevgreaterelement(int arr[],int n,vector<int>&ans)
{
    stack<int> s;
    s.push(-1);
    for(int i=0;i<n;i++)
    {
      while(s.top()!=-1 && s.top()<=arr[i])
      {
        s.pop();
      }
      ans.push_back(s.top());
      s.push(arr[i]);
    }
}

int main() 
{
    int arr[] = {8,8,6,2,3};
    int n = 5;
    vector<int> ans;

    //prevSmallerElement(arr,n,ans);
    nextSmallerElement(arr,n,ans);
    //nextgreaterelement(arr,n,ans);
    //prevgreaterelement(arr,n,ans);
    for(auto i: ans) 
    {
        cout << i << " ";
    }

  return 0;
}
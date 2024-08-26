
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

void inserter(vector<int>&vect)
{
    int size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        int val;
        cin>>val;
        vect.push_back(val);
    }
}


void printer(vector<int>&vect)
{
    for(int i=0;i<vect.size();i++)
    {
        cout<<vect[i]<<"   ";
    }
    cout<<endl;
}

void printer(vector<string>&vect)
{
    for(int i=0;i<vect.size();i++)
    {
        cout<<vect[i]<<"   ";
    }
    cout<<endl;
}

void summer(vector<int>&v1,vector<int>&v2,vector<string>&ans)
{
    int carry=0;
    int i=v1.size()-1;
    int j=v2.size()-1;
    while(i>=0 && j>=0)
    {
        int x=v1[i]+v2[j]+carry;
        int digit=x%10;
        ans.push_back(to_string(digit));
        carry=x/10; 
        i--,j--;
    }
    while(i>=0 )
    {
        int x=v1[i]+0+carry;
        int digit=x%10;
        ans.push_back(to_string(digit)); 
        carry=x/10;
        i--;
    }
    while(j>=0)
    {
        int x=v1[j]+0+carry;
        int digit=x%10;
        ans.push_back(to_string(digit));
        carry=x/10;
        j--; 
    }
    while(ans[ans.size()-1]=="0")
    {
        ans.pop_back();
    }
    reverse(ans.begin(),ans.end());
}



int main()
{
    
   vector<int>arr;
   vector<int>brr;
   vector<string>ans;
   inserter(arr);
   inserter(brr);
   printer(arr);
   printer(brr);
   summer(arr,brr,ans);
   printer(ans);
}

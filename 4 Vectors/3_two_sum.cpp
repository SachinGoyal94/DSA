//find pairs whose sum of elements =specific value

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void inserter(vector<int>&p)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        p.push_back(d);
    }
}

void printer(vector<int>&p)
{
    for(int i=0;i<p.size();i++)
    {
        cout<<p[i]<<endl;
    }
}

void finder(vector<int>&p,int target)
{
    for(int i=0;i<p.size();i++)
    {
        for(int j=0;j<p.size();j++)
        {
            if(p[i]+p[j]==target)
            {
                cout<<p[i]<<" , "<<p[j]<<endl;
            }
        }
    }
}
int main()
{
    vector<int>arr;
    int target;
    cin>>target;
    inserter(arr);
    printer(arr);
    finder(arr,target);
}
//find triplets whose sum=specific target value

#include<iostream>
#include<algorithm>
#include<vector>

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

void finder(vector<int>&p,vector<vector<int>>&ans,int target)
{
    for(int i=0;i<p.size();i++)
    {
        for(int j=i+1;j<p.size();j++)
        {
            for(int k=i+2;k<p.size();k++)
            {
                if(p[i]+p[j]+p[k]==target)
                {
                vector<int>temp;
                temp.push_back(p[i]);
                temp.push_back(p[j]);
                temp.push_back(p[k]);
                ans.push_back(temp);
                }
            }
        }
    }
}

void triplets(vector<vector<int>>&ans)
{
    cout<<"size of ans is: "<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<"   ";
        }
        cout<<endl;
    }
}

int main() 
{
    vector<int>p;
    vector<vector<int>>ans; //ans is a vector having many vector inside it like
                            //{{10,20,30},{20,25,30}}  it's like 2-D vector consisting of many 1-D vectors inside it
    int target;
    cin>>target;

    inserter(p);
    printer(p);
    finder(p,ans,target);
    triplets(ans);
}
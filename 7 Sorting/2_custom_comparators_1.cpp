//using custom comparators we can modify the use of any inbuilt function

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printv(vector<int>&v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<"  ";
    }
    cout<<endl;
}
bool mycom(int &a,int &b)
{
    //return a<b; //ascending order
    
    return a>b; //descending order
}
int main()
{
    vector<int>v{33,22,44,55,11};
    sort(v.begin(),v.end());
    printv(v);
    sort(v.begin(),v.end(),mycom);
    printv(v);
}
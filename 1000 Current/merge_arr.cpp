#include<bits/stdc++.h>
using namespace std;
void sorter(int low,int mid,int high,vector<int>&arr)
{
    int leftlength=mid-low+1;
    int rightlength=high-mid;
    vector<int>lefty(leftlength),righty(rightlength);
    int s=low;
    for(int i=0;i<leftlength;i++)
    {
        lefty[i]=arr[s];
        s++;
    }
    int h=mid+1;
    for(int i=0;i<leftlength;i++)
    {
        righty[i]=arr[h];
        h++;
    }
    int i=0,j=0,mainindex=low;
    while(i<leftlength && j<rightlength)
    {
        if(lefty[i]<righty[j])
        {
            arr[mainindex]=lefty[i];
            i++;
            mainindex++;
        }
        else
        {
            arr[mainindex]=righty[j];
            j++;
            mainindex++;
        }
    }
    while(i<leftlength)
    {
        arr[mainindex]=lefty[i];
        i++;
    }
    while(j<leftlength)
    {
        arr[mainindex]=righty[j];
        j++;
    }
}


void solve(int low,int high,vector<int>&arr)
{
    if(low==high)
        return ;
    int mid=low+(high-low)/2;
    solve(low,mid,arr);
    solve(mid+1,high,arr);
    //parts hogye abb sum nikal do 

    sorter(low,mid,high,arr);
}
int main()
{
    vector<int>arr{-2,-5,6,-2,-6,1,5,-6};
    solve(0,7,arr);
    for(auto & i:arr)
    {
        cout<<i<<endl;
    }
}
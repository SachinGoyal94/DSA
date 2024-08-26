#include<bits/stdc++.h>
using namespace std;
bool searcher(int arr[],int size,int index,int target)
{
    if(index>=size)
    {
        return false;
    }
    if(target==arr[index])
    {
        return true;
    }
    bool ans=searcher(arr,size,index+1,target);
    return ans;
}
int maxelement(int arr[],int size,int index,int &ans) //if we are storing value must send by 
                                                    //reference so to make change in actual not in copy
{
    if(index==size)
    {
        return ans;
    }
    ans=max(ans,arr[index]);
    int maxele=(maxelement(arr,size,index+1,ans));
    return maxele;
}
int minelement(int arr[],int size,int index,int &ans)                                               
{
    if(index==size)
    {
        return ans;
    }
    ans=min(ans,arr[index]);
    int minele=(minelement(arr,size,index+1,ans));
    return minele;
}

void odds(int arr[],int size,int index)
{
    if(index==size)
    {
        return;
    }
    if(arr[index]&1)
    {
        cout<<arr[index]<<"   ";
    }
    odds(arr,size,index+1);
}
void even(int arr[],int size,int index)
{
    if(index==size)
    {
        return;
    }
    if(!(arr[index]&1))
    {
        cout<<arr[index]<<"  ";
    }
    even(arr,size,index+1);
}
int main()
{
    int arr[10]={61,53,32,80,40};
    //cout<<searcher(arr,5,0,30);
    int maxi=INT_MIN,mini=INT_MAX;
    int size=5,index=0;
    //cout<<maxelement(arr,5,0,maxi);
    //cout<<minelement(arr,5,0,mini);
    //odds(arr,5,0);
    even(arr,5,0);

}
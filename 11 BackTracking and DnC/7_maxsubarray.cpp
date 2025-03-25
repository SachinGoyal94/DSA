#include<bits/stdc++.h>
using namespace std;
int findleft(int low,int high,vector<int>arr)
{
    int sum=0,maxi=INT_MIN;
    for(int i=high;i>=low;i--)
    {
        sum+=arr[i];
        maxi=max(sum,maxi);
    }
    return maxi;
}

int findright(int low, int high, vector<int>& arr) {
    int sum = 0, maxi = INT_MIN;
    for(int i = low; i <= high; i++) {
        sum += arr[i];
        maxi = max(sum, maxi);
    }
    return maxi;
}


int solve(int low,int high,vector<int>arr)
{
    if(low==high)
        return arr[low];
    int mid=low+(high-low)/2;
    int left=solve(low,mid,arr);
    int right=solve(mid+1,high,arr);
    //parts hogye abb sum nikal do 

    int leftsum=findleft(low,mid,arr);
    int rightsum=findright(mid+1,high,arr);
    int cross=leftsum+rightsum;
    return max({cross,left,right});

}
int main()
{
    vector<int>arr{-2,-5,6,-2,-6,1,5,-6};
    int sum=solve(0,7,arr);
    cout<<sum;
}
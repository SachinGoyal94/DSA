//TC O(n^2)   for avg case nlog(n)
#include<bits/stdc++.h>
using namespace std;
void quickSort(int arr[], int low, int high)
{
    if(low>=high)
        return;
    int pivot=high,i=low-1,j=low;
    while(j<pivot)
    {
        if(arr[j]<arr[pivot])
        {
            ++i;
            swap(arr[i],arr[j]);
        }
        ++j;
    }
    i++;
    swap(arr[i],arr[pivot]);
    quickSort(arr,low,i-1);
    quickSort(arr,i+1,high);
}
int main()
{
    int arr[8]={7,2,6,4,1,3,5,8};
    quickSort(arr,0,7);
    for(auto & it : arr)
        cout<<it<<" ";
}
//check recursion tree in notes
//TC=n*log(n)  SC=o(n)
#include<bits/stdc++.h>
using namespace std;
void merger(int arr[],int s,int e,int mid)
{
    int leftlength=mid-s+1;
    int rightlength=e-mid;
    int *leftarr=new int[leftlength];
    int *righttarr=new int[rightlength];
    int index=s;
    for(int i=0;i<leftlength;i++)
    {
        leftarr[i]=arr[index];
        index++;
    }
    index=mid+1;
    for(int i=0;i<rightlength;i++)
    {
        righttarr[i]=arr[index];
        index++;
    }
    int i=0,j=0,main_index=s;
    while(i<leftlength && j<rightlength)
    {
        if(leftarr[i]<righttarr[j])
        {
            arr[main_index]=leftarr[i];
            main_index++;
            i++;
        }
        else
        {
            arr[main_index]=righttarr[j];
            main_index++;
            j++;
        }
    }
    while(i<leftlength)
    {
        arr[main_index]=leftarr[i];
        main_index++;
        i++;
    }
    while(j<rightlength)
    {
        arr[main_index]=righttarr[j];
        main_index++;
        j++;
    }
    delete[] leftarr;
    delete[] righttarr;
}
void mergesort(int arr[],int i,int e)
{
    if(i>=e)
        return;
    int mid=(i+e)/2;
    mergesort(arr,i,mid);
    mergesort(arr,mid+1,e);
    merger(arr,i,e,mid);
}
int main()
{
    int arr[8]={10,90,30,40,20,15,25,18};
    mergesort(arr,0,7);
    for(int i=0; i<8; i++) 
    {
        cout << arr[i] << " ";
    }
}
//filling every element of array as a single input
//fill(starting address of array,upto which size no index,value)
//fill(arr,arr+5,12)
//fill(&arr[0],arr+4,12)  wherever this format of starting address reqd we can use reference to start operation from any index 

#include<iostream>        
using namespace std;
int main()
{
    int n,l; //although used here but never input n and then give it as size of array
    cin>>n>>l;
    int arr[n]={12};
    cout<<"Before filling"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }

    cout<<"after filling"<<endl;
    fill(&arr[0],arr+l,23);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
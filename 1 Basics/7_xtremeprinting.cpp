#include<iostream>
using namespace std;
void pass(int a[],int size)
{
    cout<<"enter values in array"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    cout<<endl;
}

void print(int a[],int size)
{
    cout<<"printing values in array"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<endl;
    }
}

void xtremeprinting(int a[],int size)
{
    pass(a,size);   //whenever passing array into function never code A[] but simply A
    print(a,size);
    cout<<"starting xtreme printing"<<endl;
    int i=0,j=size-1;
    while(i<=j)
    {
        cout<<a[i]<<endl;
        
        if(i==j)
        {
            break;
        }
        
        else{
        cout<<a[j]<<endl;
        j--;
        }
        
        i++;
    }
}
int main()
{
    int A[13];
    cout<<"Enter size of array"<<endl;
    int size;
    cin>>size;
    xtremeprinting(A,size);
}

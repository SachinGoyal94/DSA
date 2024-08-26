#include<iostream>
using namespace std;
void pass(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
}

void print(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<endl;
    }
}


void reverse(int a[],int size)
{
    cout<<"before reversing the array"<<endl;
    cout<<"input the array"<<endl;
    pass(a,size);
    cout<<"print the original array"<<endl;
    print(a,size);
    for(int i=0;i<(size/2);i++)
    {
        int temp=a[i];
        a[i]=a[size-1-i];
        a[size-1-i]=temp;
    }
    cout<<"print after reversing the array"<<endl;
    print(a,size);
}
int main()
{
    int A[13];
    int size;
    cin>>size;
    reverse(A,size);
}

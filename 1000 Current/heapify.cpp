#include<bits/stdc++.h>
using namespace std;
void heapify(int *arr,int i,int index)  //index is no of elements
{
    int largestvalueindex=i;  //suppose i pe largest value
    int leftchild=2*i;
    int rightchild=(2*i)+1;
    if(leftchild<index && arr[leftchild]>arr[largestvalueindex])
    {
        largestvalueindex=leftchild;
    }
    if(rightchild<index && arr[rightchild]>arr[largestvalueindex])
    {
        largestvalueindex=rightchild;
    }
    if(largestvalueindex!=i)
    {
        swap(arr[i],arr[largestvalueindex]);
        i=largestvalueindex;
        heapify(arr,i,index);
    }
}
void buildheap(int *arr,int n)
{
    for(int i=(n/2);i>=1;i--)
    {
        heapify(arr,i,n);
    }
}
void HeapSort(int *arr,int n)
{
    while(n>1)//n=1 pe single node which is always sorted 
    {
        swap(arr[1],arr[n-1]);
        n--;
        heapify(arr,1,n);
    }

}
class Heap
{
    public:
    int *arr;
    int size;
    int index;
    Heap(int n)
    {
        size=n;
        index=0;//jab bhi mujhe insert krna hoga, tab index+1 krke insert krdena
        arr=new int[n];  //0 se start coz left child ka index acc. to level order array is 2*i and that rightchild=2*i+1
    }
    void insert(int val)
    {
        if(index==size)
        {
            cout<<"Heap overflow"<<endl;
            return;
        }
        index++;
        int i=index;
        arr[i]=val;
        while(i>1)
        {
            int parentindex=i/2;
            if(arr[parentindex]<arr[i])
            {
                swap(arr[parentindex],arr[i]);
                i=parentindex;
            }
            else
            {
                break;
            }
        }
    }
    void printHeap()
    {
        for(int i=1;i<=index;i++)//parent index ko 1 se start kiya index print krne se inserted elements aayenge
                                 // size se sare aa jayenge so garbage values inside array also printed and deleted nodes also get printed 
        {
            cout<<arr[i]<<"    ";
        }
        /*
        for(int i=1; i<size; i++) 
        {
        	cout << arr[i] << " ";  
        }
		cout << endl;
        */
    }
    void deletion()  //deletion of root node always
    {
        swap(arr[1],arr[index]);
        index--;
        heapify(arr,1,index);
    }
};

int main()
{
    cout<<"build heap of array"<<endl;
    int arr[10]={-1,10,20,30,40,50};// 50 10 30 40 20 
    int n=6;
    buildheap(arr,n);
    cout<<"heap builded"<<endl;
    for(int i=1;i<n;i++)
        cout<<arr[i]<<"    ";
    cout<<endl;
    arr[6]=60;
    buildheap(arr,7);
    for(int i=1;i<7;i++)
        cout<<arr[i]<<"    ";
    cout<<endl;
    
    // cout<<"Heap Sort"<<endl;
    // HeapSort(arr,n);
    // for(int i=1;i<n;i++)
    //     cout<<arr[i]<<"    ";
    // cout<<endl;
    
    
    // Heap h(5);
    // h.insert(10);
    // h.insert(20);
    // h.insert(30);
    // h.insert(40);
    // h.insert(50);
    // h.printHeap();
    // cout<<endl;

    // h.deletion();
    // h.printHeap();
    // cout<<endl;

    // h.deletion();
    // h.printHeap();
    // cout<<endl;

    // h.deletion();
    // h.printHeap();
    // cout<<endl;

    // h.deletion();
    // h.printHeap();
    // cout<<endl;

    // h.deletion();
    // h.printHeap();
    // cout<<endl;
}
/* for using function in vector use  fun(vector<int>&v)  & must be use otherwise call by value concept will 
get implemented
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void inserter(vector<int>&v)
{
    cout<<"how many value you want to input"<<endl;
    int n;
    cin>>n;
    cout<<"enter the values"<<endl;
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        v.push_back(d);
    }
    cout<<endl;
}

void printer(vector<int>&v)
{
    int size=v.size();
    cout<<"current size of vector is "<<size<<endl;
    cout<<"printing all values"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<i<<"   "<<v[i]<<endl;
    }
    cout<<endl;
}

void extender(vector<int>&v)
{
    int size;
    size=v.size();
    cout<<"current size of vector is"<<size<<endl;
    cout<<"if user wants to add more elements in the vector"<<endl;
    int elem;
    cout<<"enter no of elements";
    cin>>elem;
    for(int i=size;i<(size+elem);i++)
    {
        int d;
        cin>>d;
        v.push_back(d);
    }
    cout<<"current size is "<<v.size()<<endl;
    cout<<endl;
}

void deleter(vector<int>&v)
{
    cout<<"popping elements of vector from last"<<endl;
    int size;
    size=v.size();
    cout<<"current size of vector is"<<size<<endl;
    int elem;
    cout<<"enter no of elements to be deleted";
    cin>>elem;
    for(int i=(size-1);i>size-1-elem;i--)
    {
        v.pop_back();
    }
    cout<<"after deletion size is "<<v.size()<<endl;
    if(v.size()==(size-elem))
    {
        cout<<"deletion done succesfully"<<endl;
    }
    else
    {
        cout<<"deletion not done properly"<<endl;
    }
    cout<<endl;
    printer(v);
    cout<<endl;
}

void clearer(vector<int>&v)
{
    cout<<"using inbuilt function to delete all elements of vector "<<endl;
    v.clear();
    printer(v);
    if(v.size()==0)
    {
        cout<<"whole vector is cleared successfully"<<endl;
    }
    else
    {
        cout<<"error in function clearer"<<endl;
    }
}

void fewinbuilt_functions(vector<int>&v,vector<int>&swapper)
{
    cout<<"current size of vector is : "<<v.size()<<endl;
    cout<<"first element ***use this method*** "<<v[0]<<endl;
    cout<<"first element using v.front()"<<v.front()<<endl;
    cout<<"last element ***use this method*** "<<v[v.size()-1]<<endl;
    cout<<"last element using v.back()"<<v.back()<<endl;
    
    cout<<"*v.begin() prints intital value "<<*(v.begin())<<endl;
    cout<<"*v.end() print value next to last value : "<<*v.end()<<endl;

    if(v.empty()==0)
    {
        cout<<"v.empty() checks size is 0 or not"<<endl;
    }
    cout<<"v.reserve(required size) reserve current+reqd capacity but it may now work instantly so we may use v.resize(size reqd)"<<v.capacity()<<endl;
    v.reserve(100);
    v.resize(30);
    cout<<"after resize "<<v.capacity()<<endl;
    
    cout<<"current size of vector is : "<<v.size()<<endl;

    cout<<"max element vector can hold is : "<<v.max_size()<<endl;

    v.insert(v.begin()+1,4);  // before index 1 add element so new value will be there after index zero that means each index increase by 1 after zero here 
    cout<<"inserting 1 more element before any index using insert(index,value) "<<endl;
    printer(v);    

    cout<<"erasing from specific index to particular index"<<endl;
    v.erase(v.begin()+6,v.end());
    printer(v);

    v.swap(swapper);   //interchanging both vectors 
    printer(v);
    printer(swapper);
    
}

void iterating(vector<int>&v)
{
    vector<int>::iterator it=v.begin();

    cout<<"iterating throughout the vector"<<endl;
    while(it!=v.end())
    {
        cout<<*it<<endl;
        it++;
    }
}


void foreachloop(vector<int>&v)
{
    cout<<"using for each loop to print vector"<<endl;
    for(auto it:v)
    {
        cout<<it<<endl;
    }
    cout<<endl;
}


void caution(vector<int>&v)
{
    cout<<"auto will not work in pointers"<<endl;
}

int main()
{
    vector<int>arr;
    vector<int>swapped;
    cout<<"current size is "<<arr.size()<<endl;
    inserter(arr);
    printer(arr);
    extender(arr);
    printer(arr);
    cout<<"capacity of vector is "<<arr.capacity()<<endl;
    deleter(arr);
    cout<<"capacity of vector is "<<arr.capacity()<<endl;

    //clearer(arr);

    cout<<"now for swapped vector input and outputs are : "<<endl;
    inserter(swapped);
    printer(swapped);

    fewinbuilt_functions(arr,swapped);
    iterating(arr);
    foreachloop(arr);
    caution(arr);
}
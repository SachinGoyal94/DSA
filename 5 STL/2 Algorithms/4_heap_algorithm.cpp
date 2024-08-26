//if we have declare any container like vector and now we want to convert it into heap 
//then heap algo is used

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<int>v;
    v.push_back(20);
    v.push_back(30);
    v.push_back(10);
    v.push_back(60);
    v.push_back(40);
    v.push_back(50);
    for(auto& a:v)                       
    {
        cout<<a<<endl;
    }

    make_heap(v.begin(),v.end());        //container into heap

    cout<<"after coverting into heap"<<endl; 

    for(auto& a:v)                       
    {
        cout<<a<<endl;
    }

    v.push_back(99);
    push_heap(v.begin(),v.end());        //push heap ensures the max element to be at index 0     
    cout<<"after insertion"<<endl;       //but doesn't ensures sorting of whole container
    for(auto& a:v)                       
    {
        cout<<a<<endl;
    }


    pop_heap(v.begin(),v.end());        // max element moves to last position 
    cout<<"before deletion"<<endl;
    for(auto& a:v)                     
    {
        cout<<a<<endl;
    }
    v.pop_back();                      //now use container function to remove element
    cout<<"after deletion"<<endl;
    for(auto& a:v)                     
    {
        cout<<a<<endl;
    }


    sort_heap(v.begin(),v.end());
    cout<<"after sorting "<<endl;
    for(auto& a:v)                     
    {
        cout<<a<<endl;
    }

    return 0;
}
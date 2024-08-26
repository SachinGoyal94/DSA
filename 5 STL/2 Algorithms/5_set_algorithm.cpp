#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main() {

            
    vector<int> first;
    first.push_back(1);
    first.push_back(2);
    first.push_back(3);
    first.push_back(4);
            
    vector<int> second;
    second.push_back(3);
    second.push_back(4);
    second.push_back(5);
    second.push_back(6);

    vector<int> result;

    cout<<"union of 2 sets "<<endl;
    set_union(first.begin(),first.end(),second.begin(),second.end(),inserter(result,result.begin()));
    for(auto& a:result)
    {
        cout<<a<<endl;
    }

    vector<int> result1;
    cout<<"intersection of 2 sets "<<endl;
    set_intersection(first.begin(),first.end(),second.begin(),second.end(),inserter(result1,result1.begin()));
    for(auto& a:result1)
    {
        cout<<a<<endl;
    }


    vector<int> result2;
    cout<<"difference of 2 sets "<<endl;
    set_difference(first.begin(),first.end(),second.begin(),second.end(),inserter(result2,result2.begin()));
    for(auto& a:result2)
    {
        cout<<a<<endl;
    }


    vector<int> result3;
    cout<<"symetric difference of 2 sets "<<endl;
    set_symmetric_difference(first.begin(),first.end(),second.begin(),second.end(),inserter(result3,result3.begin()));
    for(auto& a:result3)
    {
        cout<<a<<endl;
    }


    
    
}
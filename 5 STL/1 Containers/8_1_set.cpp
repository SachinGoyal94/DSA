#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;
int main()
{
    //unordered set
    unordered_set<int> sets;
    sets.insert(10); 
    sets.insert(20);
    sets.insert(30);
    sets.insert(40); 
    cout<<"size of set is "<<sets.size()<<endl;

    unordered_set<int>::iterator it=sets.begin();
    while(it!=sets.end())
    {
        cout<<*it<<endl;
        it++;
    }

    //sets.clear()
    //sets.erase(sets.begin(),sets.end())

    if(sets.empty())
    {
        cout<<"empty set"<<endl;
    }
    else
    {
        cout<<"non empty set"<<endl;
    }

    if(sets.find(30)!=sets.end())
    {
        cout<<"found"<<endl;
    }
    else
    {
        cout<<"not found"<<endl;
    }

    if(sets.count(40)==1)
    {
        cout<<"found"<<endl;
    }
    else
    {
        cout<<"not found"<<endl;
    }
}
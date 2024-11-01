#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    //vector<int>::iterator it=v.begin();   auto it=v.begin() also correct
    auto it=v.begin();
    it=it+2;
    cout<<*it<<endl;
    cout<<"ok ok"<<endl;
    while(it!=v.end())
    {
        cout<<*it<<endl;
        it++;
    }

    //using for loop
    auto kt=v.begin();
    for(kt=v.begin();kt!=v.end();kt++)
    {
        cout<<*kt<<endl;
    }
}
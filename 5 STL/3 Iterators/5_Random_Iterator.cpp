//Random iterator 

#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<forward_list>
using namespace std;
int main()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator itr=v.begin()+2;  //randomly accessed

    while(itr!=v.end())
    {
        cout<<*itr<<endl;   //read 
        itr++;
    }

}

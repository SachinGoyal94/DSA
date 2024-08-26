#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int a=10,b=2;
    cout<<max(a,b)<<endl;
    cout<<min(a,b)<<endl;

    vector<int>v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    auto it=max_element(v1.begin(),v1.end());
    cout<<*it<<endl;

    auto kt=min_element(v1.begin(),v1.end());
    cout<<*kt<<endl;
}
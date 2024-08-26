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
    v.push_back(40);

    sort(v.begin(),v.end());

    cout<<"sorting is must "<<endl;
    for(auto& a:v)
    {
        cout<<a<<endl;
    }

    int target=40;
    bool ans=binary_search(v.begin(),v.end(),target);
    cout<<ans<<endl;

    auto it=upper_bound(v.begin(),v.end(),target);
    cout<<*it<<endl;

    auto kt=lower_bound(v.begin(),v.end(),target);
    cout<<*kt<<endl;

    auto iterat=equal_range(v.begin(),v.end(),target);
    cout<<(iterat.first-v.begin())<<endl;
    cout<<(iterat.second-v.begin())<<endl;

    //iterat.first tells the first index where target is present
    //   *iterat.second=50 so before 50 40 is there so 
    //iterat.second-v.begin tells till which index where the  target is present in sorted order 
    //but does not include that index only upto

}
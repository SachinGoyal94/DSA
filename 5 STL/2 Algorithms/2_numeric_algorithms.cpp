#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;
int main()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);

    cout<<"intial vector is "<<endl;
    for(auto& a:v)
    {
        cout<<a<<endl;
    }
    
    int totalsum=accumulate(v.begin(),v.end(),150);   //total sum=150
    cout<<"total sum of elements of vector is "<<totalsum<<endl;

    vector<int>v1;
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    cout<<"initial vector v1 with non initialised 5th index "<<endl;
    for(int i=0;i<(v1.size()+1);i++)
    {
        cout<<v1[i]<<endl;
    }

    cout<<"inner products of two vectors "<<endl;
    int ans=inner_product(v.begin(),v.end(),v1.begin(),0);  //ans=0
    cout<<ans<<endl;                                        //se at v1[6]=0


    vector<int>result(v.size());
    partial_sum(v.begin(),v.end(),result.begin());   //gives cumulative sum of data in the container
    cout<<"vector of cumulative sum "<<endl;
    for(auto& a:result)
    {
        cout<<a<<endl;
    }

    cout<<"vector v after operating algo iota on it "<<endl;
    iota(v.begin(),v.end(),250);
    for(auto& a:v)
    {
        cout<<a<<endl;
    }
    
    
}
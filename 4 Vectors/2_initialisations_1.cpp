#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<int>v; //default with no data, 0 size

    vector<int>k(10); //10 is the size

    vector<int>v1(5,-1);  //size is 5 and all values=-1
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<endl;
    }
    
    cout<<endl;

    vector<int>v2 ={1,2,3,4,5};
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i]<<endl;
    }
    
    cout<<endl;

    vector<int>v3{11,12,13,14,15};
    for(int i=0;i<v3.size();i++)
    {
        cout<<v3[i]<<endl;
    }

    cout<<endl;

    cout<<"copying vectors"<<endl;

    vector<int>v4(v3); 
    for(int i=0;i<v4.size();i++)
    {
        cout<<v4[i]<<endl;
    }

}
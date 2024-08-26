#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<vector<int>>arr(5,vector<int>(4,0));
    int total_rows=arr.size();
    int total_columns=arr[0].size();
    cout<<"for vector arr details are : "<<endl;
    cout<<"no of rows are "<<total_rows<<endl;
    cout<<"no of columnss are "<<total_columns<<endl;    
    //2d vector with 5 rows 4 columns and 0 as value

    vector<vector<int>>brr(5);  //5 rows
    brr[0]=vector<int>(2);      //row 1 has 2 columns
    brr[1]=vector<int>(6);      //row 2 has 6 columns    
    brr[2]=vector<int>(3);      //row 3 has 3 columns
    brr[3]=vector<int>(4);      //row 4 has 4 columns
    brr[4]=vector<int>(5);      //row 5 has 5 columns
    int tr=brr.size();
    cout<<"for vector brr details are : "<<endl;
    cout<<"no of rows are "<<tr<<endl;
    for(int i=0;i<brr.size();i++)
    {
        cout<<"no of columns in row "<<i+1<<" : "<<brr[i].size()<<endl;
    }

    cout<<" inserting values inside 2 d vector "<<endl;
    for(int i=0;i<brr.size();i++)
    {
        for(int j=0;j<brr[i].size();j++)
        {
            int val;
            cin>>val;
            brr[i][j]=val;         //pushback not allowd 
        }
    }
    for(auto& a:brr)
    {
        for(auto & b:a)
        {
            cout<<b<<"   ";
        }
        cout<<endl;
    }
}
#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main()
{
    cout<<"unordered maps gives output not in alphanumerical order or keys"<<endl;
    unordered_map<int,string> table;
    table[1]="India";
    table.insert(make_pair(2,"Austria"));

    pair<int,string> p;
    p.first=3;
    p.second="England";
    table.insert(p);

    cout<<table.at(1)<<endl;
    table.at(1)="Bharat";

    cout<<table.size()<<endl;

    unordered_map<int,string>::iterator it=table.begin();
    while(it!=table.end())
    {
        pair<int,string> paired=*it;
        cout<<paired.first<<"   "<<paired.second<<endl;
        it++;
    }

    cout<<"in the map we find the value using pair "<<endl;
    
    int n;
    cout<<"enter the key you want to find "<<endl;
    cin>>n;

    if(table.find(n)!=table.end())
    {
        int k=table.count(n);  //count() returns 1 if key founded 
        cout<<k<<endl;
    }
    else
    {
        int k=table.count(n);  //count() returns 0 if key not founded 
        cout<<k<<endl;
    }


    //table.erase(table.begin(),table.end());
    //cout<<table.size()<<endl;

    // table.clear();

    // if(table.empty()==1)
    // {
    //     cout<<"empty table"<<endl;
    // }
    // else{
    //     cout<<"non empty table"<<endl;
    // }
}
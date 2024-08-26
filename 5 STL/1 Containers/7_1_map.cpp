#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main()
{

    cout<<"ordered maps gives output  in alphanumerical order or keys"<<endl;
    
    map<string,string> table;       //for ordered map
    table["in"]="India";
    table.insert(make_pair("au","Austria"));

    pair<string,string> p;
    p.first="eng";
    p.second="England";
    table.insert(p);

    cout<<table.at("in")<<endl;
    table.at("in")="Bharat";

    cout<<table.size()<<endl;

    map<string,string>::iterator it=table.begin();
    while(it!=table.end())
    {
        pair<string,string> paired=*it;
        cout<<paired.first<<"   "<<paired.second<<endl;
        it++;
    }

    cout<<"in the map we find the value using pair "<<endl;
    
    string n;
    cout<<"enter the key you want to find "<<endl;
    getline(cin,n);

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


    table.erase(table.begin(),table.end());
    cout<<table.size()<<endl;

    table.clear();

    if(table.empty()==1)
    {
        cout<<"empty table"<<endl;
    }
    else{
        cout<<"non empty table"<<endl;
    }
}
#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main()
{

    cout<<"ordered maps gives output  in alphanumerical order or keys"<<endl;
    
    map<string,string> table;       
    table["in"]="India";
    table.insert(make_pair("au","Austria"));

    map<string,string>::iterator itr=table.begin();
    pair<string,string> p=*itr;                    
    while(itr!=table.end())
    {
        cout<<(*itr).first<<"   "<<(*itr).second<<endl;  //as iterator is pointing with pair
        itr++;
    }

    //or
    map<string,string>::iterator ktr=table.begin();
    while(ktr!=table.end())
    {
        cout<<ktr->first<<"   "<<ktr->second<<endl;  //as iterator is pointing with pair
        ktr++;
    }

}
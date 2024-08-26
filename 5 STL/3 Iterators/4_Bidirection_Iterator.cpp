//Bi-directional iterator 

#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<forward_list>
#include<map>
using namespace std;
int main()
{
    list<int>mylist;
    mylist.push_back(10);
    mylist.push_back(20);
    mylist.push_back(30);
    mylist.push_back(40);
    mylist.push_back(50);

    list<int>::iterator itr=mylist.end();

    while(itr!=mylist.begin())
    {
        //*itr=*itr+5;            //write 
        itr--;              //move
        
        //itr-- must be before printing as itr=mylist.end() so it referes to boundary of list 

        cout<<*itr<<endl;   //read 
    }

    cout<<"Bi directional iterator with map "<<endl;

    map<string,string> table;       
    table["in"]="India";
    table["cn"]="china";
    table.insert(make_pair("au","Austria"));

    map<string,string>::iterator it=table.end();
    while(it!=table.begin())
    {
        it--;
        cout<<(*it).first<<"   "<<(*it).second<<endl; 
    }
}
/*

    map<string,string>::iterator itr=table.r();begin    //rbegin() start from end 
    pair<string,string> p=*itr;                       
    while(itr!=table.rend())                        //rend() move towards begin 
    {
        itr--;
        cout<<(*itr).first<<"   "<<(*itr).second<<endl; 
    }
}
*/
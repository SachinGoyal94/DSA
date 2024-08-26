#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int>mylist;

    cout<<"size of mylist is "<<mylist.size()<<endl;

    //creation
    mylist.push_back(10);
    mylist.push_back(20);
    mylist.push_back(30);
    mylist.push_back(40);

    cout<<"size of mylist is "<<mylist.size()<<endl;


    mylist.push_front(100);        //100->10->20->30->40

    mylist.pop_back();             //100->10->20->30

    mylist.pop_front();            //10->20->30

    cout<<"mylist.front() "<<mylist.front()<<endl;

    cout<<"mylist.back() "<<mylist.back()<<endl;

    cout<<"size of mylist is "<<mylist.size()<<endl;

    mylist.insert(mylist.begin(),500);

    list<int>::iterator it=mylist.begin();
    while(it!=mylist.end())
    {
        cout<<*it<<endl;
        it++;
    }
    

    list<int>yourlist;

    cout<<"size of yourlist is "<<yourlist.size()<<endl;

    //creation
   yourlist.push_back(21);
    yourlist.push_back(22);
    yourlist.push_back(23);
    yourlist.push_back(24);
    yourlist.push_back(25);
    yourlist.push_back(22);

    //swap
    mylist.swap(yourlist);

    list<int>::iterator it2=mylist.begin();
    while(it2!=mylist.end())
    {
        cout<<*it2<<endl;
        it2++;
    }

    mylist.remove(22);

    cout<<"after removing a constant value from the list "<<endl;

    list<int>::iterator it3=mylist.begin();
    while(it3!=mylist.end())
    {
        cout<<*it3<<endl;
        it3++;
    }


    mylist.erase(mylist.begin(),mylist.end());
    mylist.clear();
    if(mylist.empty()==1)
    {
        cout<<"size will be zero after using clear or erasing "<<mylist.size()<<endl;
    }
    else
    {
        cout<<"erasing done partially and clear() not used "<<mylist.size()<<endl;
    }
}
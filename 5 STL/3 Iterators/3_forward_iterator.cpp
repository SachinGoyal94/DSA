#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<forward_list>

using namespace std;
int main()
{
    forward_list<int>mylist;
    mylist.push_front(10);
    mylist.push_front(20);
    mylist.push_front(30);
    mylist.push_front(40);
    mylist.push_front(50);

    forward_list<int>::iterator itr=mylist.begin();

    while(itr!=mylist.end())
    {
        *itr=*itr+5;            //write 

        cout<<*itr<<endl;   //read 

        itr++;              //move
    }
}
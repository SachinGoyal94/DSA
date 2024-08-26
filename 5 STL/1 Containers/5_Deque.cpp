#include<iostream>
#include<deque>
using namespace std;
int main()
{
    deque<int>d;

    d.push_back(20);
    d.push_front(10);
    d.push_back(30);
    d.push_back(40);
    d.push_back(50);
    d.push_back(60);
    d.push_back(70);
    d.push_back(80);

    d.pop_back();
    d.pop_front();

    deque<int>::iterator it=d.begin();
    while(it!=d.end())
    {
        cout<<*it<<endl;
        it++;
    }

    //d.clear();
    //d.erase(d.begin(),d.end())

    deque<int>deques;

    deques.push_back(200);
    deques.push_front(100);
    deques.push_back(300);
    deques.push_back(400);
    deques.push_back(500);
    deques.push_back(600);
    deques.push_back(700);
    deques.push_back(800);

    deques.insert(deques.end(),900);

    d.swap(deques);
    deque<int>::iterator it1=d.begin();
    while(it1!=d.end())
    {
        cout<<*it1<<endl;
        it1++;
    }

    cout<<deques.at(1)<<endl;
    cout<<deques.front()<<endl;
    cout<<deques.back()<<endl;
    cout<<deques.size()<<endl;
    cout<<deques[1]<<endl;
}
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q;
    q.push(10); 
    q.push(20);   
    q.push(30);
    q.push(40);
    q.push(50);

    q.pop();         //pop first element

    cout<<"front -> "<<q.front()<<endl;
    cout<<"back -> "<<q.back()<<endl;
    cout<<"size -> "<<q.size()<<endl;

    if(q.empty()==1)
    {
        cout<<"queue is empty";
    }
    else
    {
        cout<<"queue is not empty"<<endl;
    }

    queue<int> q2;
    q2.push(11); 
    q2.push(21);   
    q2.push(31);
    q2.push(41);
    q2.push(51);

    q.swap(q2);

}
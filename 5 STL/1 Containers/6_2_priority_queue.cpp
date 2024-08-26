#include<iostream>
#include<queue>
using namespace std;
int main()
{
    //Min-Heap->Minimum value will get priority to get operated
    
    priority_queue<int , vector<int> , greater<int>> pq;

    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(60);
    pq.push(50);

    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    cout<<pq.size()<<endl;

 
    priority_queue<int , vector<int> , greater<int>> dq;
    
    dq.push(100);
    dq.push(200);
    dq.push(300);
    dq.push(400);
    dq.push(600);
    dq.push(500);

    pq.swap(dq);

    cout<<pq.top()<<endl;
    if(pq.empty()==1)
    {
        cout<<"empty priority queue"<<endl;
    }
    else
    {
        cout<<"non empty priority queue"<<endl;
    }

}
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.pop();

    cout<<"top element of s is -> "<<s.top()<<endl;

    cout<<"size of s is -> "<<s.size()<<endl;

    if(s.empty()==1)
    {
        cout<<"empty stack "<<endl;
    }
    else
    {
        cout<<"non empty stack "<<endl;
    }

    stack<int>s1;
    s1.push(11);
    s1.push(21);
    s1.push(31);
    s1.push(41);
    s1.push(51);

    s.swap(s1);

    cout<<"top element is s is -> "<<s.top()<<endl;
    cout<<"top element of s1 is -> "<<s1.top()<<endl;
}
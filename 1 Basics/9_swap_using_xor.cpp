#include<iostream>
using namespace std;
int main()
{
    int x,y;
    x=12;
    y=13;
    x=x^y;
    y=x^y;
    x=x^y;
    cout<<x<<endl<<y;
}  
//using arithmetic method
//a=a+b
//b=a-b
//a=a-b
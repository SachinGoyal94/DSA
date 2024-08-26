#include<iostream>
using namespace std;
int checkmyage(int n)
{
    int age=n;
    if(age>=18)
    {
        return 10; 
    }
    else{
        return -1;
    }
}
int main()
{
    int n;
    cin>>n;
    if(checkmyage(n)>=0)  //return 10 10>=0
    {
        cout<<"you can vote";
    }
    else
    {
        cout<<"better luck next time";
    } 
}
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    float i=4.4;
    cout<<ceil(i)<<endl; //prints upper value of 4.4=>5
    cout<<floor(i)<<endl; //prints lower value of 4.4=>4
    
    char a='a';
    if(isalpha(a))
    {
        cout<<"yes"<<endl;
    }

    char x='10';
    if(isdigit(x))
    {
        cout<<"ok";
    }
}
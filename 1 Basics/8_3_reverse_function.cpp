/* reverse(array,upto size to reverse)
*/

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[10];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    reverse(&a[1],a+3);
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
}
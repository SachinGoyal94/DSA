//done in recursion marathon 
#include<bits/stdc++.h>
using namespace std;
int distannce(string &a,string &b,int i,int j)
{
    if (i >= a.length() && j >= b.length()) {
        return 0;
    }
    if(i>=a.length())
    {
        return b.length()-j;
    }
    if(j>=b.length())
    {
        return a.length()-i;
    }
    int ans=0;
    if(a[i]==b[j])
    {
        ans+=distannce(a,b,i+1,j+1);
    }
    if(a[i]!=b[j])
    {
        int option1=distannce(a,b,i,j+1)+1;
        int option2=distannce(a,b,i+1,j)+1;
        int option3=distannce(a,b,i+1,j+1)+1;
        return min(option1,min(option2,option3));
    }
    return ans;
}
int main()
{
    string a="horse",b="ros";
    int i=0,j=0;
    cout<<distannce(a,b,i,j)<<endl;
}
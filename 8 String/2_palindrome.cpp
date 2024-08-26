//word like mam noun racecar who have same character at index i and (lenght-1)-i

#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    string s="racecar";
    int i=0;
    int j=s.length()-1;
    while(i<=j)
    {
        if(s[i]!=s[j])
        {
            cout<<"not a palindorme"<<endl;
        }
        if(i==j)
        {
            cout<<"palindrome";
        }
        i++;
        j--;
    }
}
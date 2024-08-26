#include<bits/stdc++.h>
using namespace std;
string reverseOnlyLetters(string s) 
{
    int i=0,j=s.length()-1;
    while(i<j)
    {
        if((isalpha(s[i])) && isalpha(s[j])) //isalpha means is aplhabetic?? if yes returns true
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
        else
        {
            if(!isalpha(s[i]))
            {
                i++;
            }
            else
            {
                j--;
            }
        }
    } 
    return s;
}
int main()
{
    string s="ab-cder-esfnes";
    string k=reverseOnlyLetters(s);
    cout<<k;
}
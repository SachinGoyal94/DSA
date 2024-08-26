#include<bits/stdc++.h>
using namespace std;
    bool isAnagram(string s, string t) 
    {
        int freqtable[256]={0};
        if(s.length()!=t.length())
        {
            return false;
        }
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            char d=t[i];
            freqtable[c]++;
            freqtable[d]--;
        }
        for(int i=0;i<256;i++)
        {
            if(freqtable[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
    int main()
    {
        string s="anangram";
        string t="nanagram";
        cout<<isAnagram(s,t);
    }
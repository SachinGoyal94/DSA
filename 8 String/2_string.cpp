#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    cout<<s<<endl;

    string a;
    a.push_back('s');
    a.push_back('a');
    a.push_back('c');
    a.push_back('h');
    a.push_back('i');
    a.push_back('n');
    a.pop_back();
    cout<<a<<endl;
    
    //stl functions
    cout<<a[0]<<endl;
    cout<<a.at(0)<<endl;
    cout<<a.front()<<endl;
    cout<<a.back()<<endl;
    cout<<a.length()<<endl;

    auto it=a.begin();
    while(it!=a.end())
    {
        cout<<*it<<"   ";
        it++;
    }
    cout<<endl;

    //a.clear();
    if(a.empty())
    {
        cout<<"empty"<<endl;
    }
    else
    {
        cout<<a<<endl;
    }

    string sentence =s+" goyal "+a;
    cout<<sentence<<endl;

    int ans=a.find("ac");
    cout<<ans<<endl;

    cout<<a.substr(2,4)<<endl; //2->index   4->no of characters to be printed upto length
    cout<<a.substr(3)<<endl;   //from index 3 upto lenght

    string s1="sachin";
    string s2="amit";
    cout<<(int)s1[0]<<"  "<<(int)s2[0]<<"    "<<s2.compare(s1)<<endl; 
    //s1 is ahead of s2 in lexographical order at first difference which is s of sachin and a of amit
    //so -1 when s2.compare s1 and 1 when s1.compare s2
    //0 when both are same

    string s3="ach";
    if(s1.find(s3)!=string::npos)  //string::npos  means string at no position founded 
    {
        cout<<"founded"<<endl;
    }
    else
    {
        cout<<"not founded"<<endl;
    }

    string sent="reversing";
    auto kt=sent.begin();
    reverse(kt+2,kt+5);
    cout<<sent<<endl;

    string eraser="sachin";
    eraser.erase(2,3);
    cout<<eraser<<endl;

    int i11=1;
    string m11;
    i11='b'-'a';
    m11='a'+2;
    cout<<i11<<"   "<<m11<<endl;

    string demo="10";
    int demo1=0;
    for(int i=0;i<demo.length();i++)
    {
        demo1=demo[i]-'0';
        cout<<demo1;
    }
}
#include<bits/stdc++.h>
using namespace std;
static bool yourcmp(string g,string b)
{
    string t1=g+b;
    string t2=b+g;
    return t1>t2;
    //t1=3038 t2=3830
    //3==3 0<8 thus 3830 is ans
}
static bool mycmp(string g,string b)
{
    return g>b;
}
int main()
{
    vector<string>g;
    g.push_back("30");
    g.push_back("38");
    sort(g.begin(),g.end(),mycmp);
    cout<<g[0]<<"   "<<g[1]<<endl;
    sort(g.begin(),g.end(),yourcmp);
    cout<<g[0]<<g[1];
}
//in string first character of each string is placed 
//in lexographical order then acc to second character they are sorted
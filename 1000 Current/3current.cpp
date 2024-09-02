#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    if (n == 1) return 1;
    int x = 1;
    for (int k = 1; k < n; ++k) {
        x += f(k) * f(n - k);
    }
    return x;
}
void permute(string &a, int l, int r)
{
    if (l == r)
        cout << a << endl;
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l + 1, r);
            swap(a[l], a[i]);
        }
    }
}
bool finder(string &s,int i,int j,int ans)
{
    if(i>j)
    {
        return ans;
    }
    if(s[i]!=s[j])
    {
        return 0;
    }
    return finder(s,i+1,j-1,ans);
}
void subsarr(vector<int>& nums,int i,int j)
{
    if(j==nums.size())
    {
        return;
    }
    for(int k=i;k<=j;k++)
        cout<<nums[k]<<"   ";
    cout<<endl;
    subsarr(nums,i,j+1);
    return ;
}
void occur(string &s,string part,int i)
{
    int j=part.length();
    if(i>=s.length())
        return ;
    if((i+j)<=(s.length()) && s.substr(i,j)==part)
    {
        s.erase(i,j);
        if(i-2>=0)
            occur(s,part,i-2);
        else
            occur(s,part,i);
    }
    occur(s,part,i+1);
}
int main() 
{
    string s="daabcbaabcbc",part="abc";
    occur(s,part,0);
    cout<<s;
    return 0;
}

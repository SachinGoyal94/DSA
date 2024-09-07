#include <bits/stdc++.h>
using namespace std;
/*
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
int dearranger(int n)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    int ans=(n-1)*(dearranger(n-2)+dearranger(n-1));
    return ans;
}
void rat(vector<vector<int>> &arr,int i,int j, string ans,vector<string>&outputs)
{
    if(i==(arr.size()-1) && j==(arr[0].size()-1))
    {
        outputs.push_back(ans);
        return ;
    }
    if (i == arr.size() || j == arr[0].size() || i < 0 || j < 0 || arr[i][j] == 0) {
        return ; // cannot reach this cell
    }
    
    int temp=arr[i][j];
    arr[i][j]=0;
    rat(arr,i+1,j,ans+'D',outputs);
    rat(arr,i,j+1,ans+'R',outputs);
    rat(arr,i,j-1,ans+'U',outputs);
    rat(arr,i-1,j,ans+'L',outputs);
    arr[i][j]=temp;
    }
int main() 
{
    /*
    int n=3;
    cout<<dearranger(n)<<endl;
    return 0;
    */
    vector<vector<int>>arr(3,vector<int>(3,1));
    arr[0][2]=0;
    arr[2][0]=0;
    arr[1][2]=0;
    string output="";
    vector<string>outputs;
    rat(arr,0,0,output,outputs);
    for(auto & ans:outputs)
        cout<<ans<<endl;
    
}
*/
/*
class Solution {
  public:
  vector<string> rat(vector<vector<int>> &arr,int i,int j,int steps,int &ans,vector<string>&answer)
    {
        if(i==(arr.size()-1) && j==(arr[0].size()-1))
        {
            return answer;
        }
        if (i == arr.size() || j == arr[0].size() || i < 0 || j < 0 || arr[i][j] == 0) {
            answer.erase();
            return answer;
        }
        
        int temp=arr[i][j];
        arr[i][j]=0;
        steps++;
        int option1=rat(arr,i+1,j,steps,ans,answer+"D";
        int option2=rat(arr,i,j+1,steps,ans,answer+"R");
        int option3=rat(arr,i,j-1,steps,ans,answer+"U");
        int option4=rat(arr,i-1,j,steps,ans),answer+"L";
        arr[i][j]=temp;
        return min(option1,min(option2,min(option3,option4)));
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int steps=0,ans=0;
        vector<string>answer;
        rat(mat,0,0,steps,ans,answer);
        return answer;
    }
}; 
*/

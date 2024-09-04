//with recursion no backtracking

#include<bits/stdc++.h>
using namespace std;
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
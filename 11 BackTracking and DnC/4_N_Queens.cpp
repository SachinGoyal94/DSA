#include<bits/stdc++.h>
using namespace std;
unordered_map<int,bool> rows;
unordered_map<int,bool> lowerdiagonal;
unordered_map<int,bool> upperdiagonal;
bool isSafe(vector<vector<char>> & board,int row ,int col)
{
    if(rows[row]==true || lowerdiagonal[row+col]==true || upperdiagonal[row-col]==true)
        return false;    
    return true;

}
vector<vector<string>> storesolution(vector<vector<char>> & board,vector<vector<string>> & ans)
{
    vector<string> tempans;
    for(int i=0;i<4;i++)
    {
        string output="";
        for(int j=0;j<4;j++)
        {
            output.push_back(board[i][j]);
        }
        tempans.push_back(output);
    }
    ans.push_back(tempans);
    return ans;
}
void placer(vector<vector<char>> & board,vector<vector<string>> &ans,int col)
{
    if(col>=4)
    {
        storesolution(board,ans);
        return;
    }
    for(int row=0;row<board.size();row++)
    {
        if(isSafe(board,row,col))
        {
            board[row][col]='Q';
            rows[row]=true;
            lowerdiagonal[row+col]=true;
            upperdiagonal[row-col]=true;            
            placer(board,ans,col+1);
            rows[row]=false;
            lowerdiagonal[row+col]=false;
            upperdiagonal[row-col]=false;
            board[row][col]='.';
        }
    }
}
int main()
{
    vector<vector<char>>board(4,vector<char>(4,'.'));
    vector<vector<string>>ans;
    placer(board,ans,0);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<ans[i][j]<<"   ";
        }
        cout<<endl;
        cout<<endl;
    }
}
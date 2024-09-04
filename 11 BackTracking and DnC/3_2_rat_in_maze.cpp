#include <bits/stdc++.h>
using namespace std;

//Backtracking means we will not repeat the same process again so here we created a visited vector which 
//only affects current recursion not further branches after final return statement

//to visualize this just think that we didn't added any statemen like "visited" before and after function called in recursion folder
    bool isSafe(int newx, int newy,vector<vector<int>> &m,vector<vector<bool>> &visited, int n ) 
    {
        if(newx < 0 || newy < 0 || newx >=n || newy >= n || visited[newx][newy] == true || m[newx][newy] == 0) {
            //out of bound
            return false;
        }
        return true;
    }
    
    void solve(vector<vector<int>> &m,vector<vector<bool>> &visited, int n,vector<string> &ans,
                int curr_x, int curr_y, int destx,int desty, string output) 
    {
        if(curr_x == destx && curr_y == desty) {
            //rat reached destination
            //store output string ko ans me 
            ans.push_back(output);
            return;
        }
        //going up
        int newx = curr_x-1;
        int newy = curr_y;
        if(isSafe(newx,newy,m,visited,n)) {
            visited[newx][newy] = true; //this is while we go into the recursion so part of backtrack
            
            output.push_back('U');  //now as we go up so print U
            
            solve(m,visited,n,ans,newx,newy,destx,desty,output+"U");
            
            output.pop_back();  //now when we get the result of this branch then we need to it delete  it for next branch that's why 
            //suppose Before this right is there now up done and after this we reach destination so now we need to next function  currx+1
            //that is going to right so delete this as after firstly right  we are going right again 
            //  down has been done in previous attempt to reach destination
            
            visited[newx][newy] = false;   //actual backtracking 

        }
        
        newx = curr_x+1;
        newy = curr_y;
        if(isSafe(newx,newy,m,visited,n)) {
            visited[newx][newy] = true;   

            solve(m,visited,n,ans,newx,newy,destx,desty,output+"D");//as not send by reference so output itself deletes D as long as recursion of 
            //this step is over for current branch  so either use output.pushback(D) or this output+"D" same thing
            
            visited[newx][newy] = false; 
        }
        
        newx = curr_x;
        newy = curr_y-1;
        
        if(isSafe(newx,newy,m,visited,n)) {
        
            visited[newx][newy] = true;
            solve(m,visited,n,ans,newx,newy,destx,desty,output+"L");
            visited[newx][newy] = false;
        
        }
        
        newx = curr_x;
        newy = curr_y+1;
        
        if(isSafe(newx,newy,m,visited,n)) {
        
            visited[newx][newy] = true;
            solve(m,visited,n,ans,newx,newy,destx,desty,output+"R");
            visited[newx][newy] = false;
        
        }
        
        return;  //you may add return or may not no compulsion as void function
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<bool> > visited(n, vector<bool>(n,0));
        //creating bool vector to let know that during a particular recursion step we have reached this place and can't again go to 
        //that place otherwise it will be infinite loop so this is called backtracking 
        int curr_x = 0;
        int curr_y = 0;
        visited[0][0] = true;
        int destx = n-1;
        int desty = n-1;
        string output = "";
        if(m[0][0] == 0) {
            return ans;
        }
        solve(m,visited,n,ans,curr_x,curr_y,destx,desty,output);
        
        return ans;
    }
int main() 
{
    vector<vector<int>>arr(3,vector<int>(3,1));
    arr[0][2]=0;
    arr[2][0]=0;
    arr[1][2]=0;
    vector<string>answerreal=findPath(arr,3);  
      for ( auto& path : answerreal) {
        cout << path << endl;
    }
}


#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
void right_down(vector<vector<int>>&nums,int &m,int &n)
{
    int i=m,j=n;     //first loop  m=0 n=0          //second loop m=i=1   n=1

    //going right
    for(j=n;j<nums[i].size()-n;j++)
    {
        cout<<nums[i][j]<<"-->";
    }
    
    i++;
    j--;

    //going down
    while(i<nums.size()-m)
    {
        cout<<nums[i][j]<<"-->";//first i=5 j=4
        i++;
    }
    
}
void left_up(vector<vector<int>>&nums,int m,int n)
{ 
    //cout<<"go left "<<endl;
    int i=nums.size()-m-1,j=nums[i].size()-2-n; //first i=4 j=2     //second m=1 n=1 i=3   j=1
    for(j=nums[0].size()-2-n;j>=(0+n);j--)
    {
        cout<<nums[i][j]<<"-->";
    }
    
    i--;                      //i=3      //i=2  
    //cout<<"go up "<<endl;
    j++;                      
    while(i>=(m+1))
    {
        cout<<nums[i][j]<<"-->";
        i--;
    }
    
}

int main()
{
    
    vector<vector<int>>arr(5,vector<int>(4));
    
    cout<<"enter input values "<<endl;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            int val;
            cin>>val;
            arr[i][j]=val;         //pushback not allowed
        }
    }

    cout<<"vector is "<<endl;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            
            cout<<arr[i][j]<<"   "; 
        }
        cout<<endl;
    }

    cout<<"spiral matrix is"<<endl;
    int k=1,m=0,n=0;
    while(k<=(4))
    {
        right_down(arr,m,n);
        left_up(arr,m,n);
        m++;
        n++;
        k++;
    }
}

/* if no of rows is 5 and columns are 4 then time and space complexity of the code is 
O(80)==O(N)==O(m*n*4) 4 bcs of while loop and O(20)==O(1) constant space complexity 

The space complexity of O(20) does not mean that the 
program uses exactly 20 units of space. Rather, it means that the 
space used by the program is directly proportional to the size of 
the input, which is m*n = 20 in this case.
In other words, the space complexity of O(20) indicates that the 
program uses a constant amount of extra space, regardless
 of the size of the input, but the amount of extra space is proportional 
to the size of the input.
In this specific example, the program uses a 2D vector arr to store the matrix,
 which has a size of mn = 54 = 20. Therefore, the program uses 20 units of space
 to store the matrix. However, the space complexity of O(20)
 does not depend on the specific value of 20, but rather on the fact that
 the space used by the program is directly proportional to the size of the input.
So, the space complexity of O(20) means that the program
 uses a constant amount of extra space, which is proportional to the size of the input,
 and in this case, the size of the input is 20.

Since m=5 and n=4, we can say that N = m*n = 20. Then, both the time complexity and space complexity can be simplified to O(N).

In other words, the time complexity is linear with respect to the size of the input, 
and the space complexity is also linear with respect to the size of the input.

So, we can conclude that both time and space complexities are O(N), where N is the total number of elements in the matrix.
*/

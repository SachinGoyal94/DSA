#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int rows = matrix.size();
    int columns = matrix[0].size();
    //total elements
    int n = rows * columns;
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    //now as we know that 2d array is also a form of 1d array so     
    //just simply using 1d binary search concept 

    while(s <= e) 
    {
        //but have to return answer as 2d array rowindex column index so 
        //using mid we will find rowindex and col index of 2d array

        //method to find row index and col index of any element in 2d array
        //represented as 1d array
        int rowIndex = mid/columns;    
        int colIndex = mid%columns;
        
        if(matrix[rowIndex][colIndex] == target) {
            cout<<rowIndex<<"  "<<colIndex<<endl;
            return true;
        }
        if(target > matrix[rowIndex][colIndex] ) {
            //right
            s = mid+1;
        }
        else {
            //left
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return false;
}

int main()
{
    vector<vector<int>>matrix(3);
    matrix[0]=vector<int>(4);
    matrix[1]=vector<int>(4);
    matrix[2]=vector<int>(4);
    int count =0;
    for(int i=0; i<matrix.size() ;i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            matrix[i][j]=++count;
        }
    }
    bool result= searchMatrix(matrix,6);
    cout<<result;
}


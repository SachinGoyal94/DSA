#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int carry=0;
    vector<int>result;
    result.push_back(1);
    cout<<"enter value whose factorial is to be calculated "<<endl;
    int N;
    cin>>N;
    for(int i=2;i<=N;i++)
    {
        for(int j=0;j<result.size();j++)
        {
            int x=result[j]*i+carry;
            result[j]=x%10;
            carry=x/10;
        }
        while(carry)
        {
            result.push_back(carry%10);
        }
        carry=carry/10;
    }
    reverse(result.begin(),result.end());
    for(int g:result)
    {
        cout<<g<<"   ";
    }
}
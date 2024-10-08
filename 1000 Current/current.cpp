#include<bits/stdc++.h>
using namespace std;
void checkseq(string s,string output,int index,vector<string>&ans)
{
    if((index)==s.length())
    {
        cout<<output<<endl;
        ans.push_back(output);
        return;
    }
    checkseq(s,output+s[index],index+1,ans);
    checkseq(s,output,index+1,ans);
}
int robber(vector<int>nums,int index)
{
    if(index>=nums.size())
    {
        return 0;
    }
    int includer=nums[index]+robber(nums,index+2);
    int excluder=0+robber(nums,index+1);
    return max(includer,excluder);
}
int main()
{
    string s="abc"; //for abc "  " is also a sequence 
    string output=" ";
    vector<string>ans;
    checkseq(s,output,0,ans);
    auto it=ans.begin();
    while(it!=ans.end())
    {
        cout<<*it<<"   ";
        it++;
    }
    cout<<endl;
    vector<int>nums{2,7,9,10,2};
    cout<<robber(nums,0);
}

//seq means if abc a comes befor b and c it can be ac or ab and empty string also allowed
//so no of subsequences=2^n


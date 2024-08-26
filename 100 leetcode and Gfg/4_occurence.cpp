
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


void firstoccurence(vector<int>&bin,int &ansindex,int target)
{
    int l=0,h=bin.size()-1;
    while(l<=h)
    {
        int mid=l+((h-l)/2);
        if(bin[mid]==target)
        {
            ansindex=mid;
            h=mid-1;
        }
        else
        {
            if(bin[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
    }
}


void lastoccurence(vector<int>&bin,int &ansindex,int target)
{
    int l=0,h=bin.size()-1;
    while(l<=h)
    {
        int mid=l+((h-l)/2);
        if(bin[mid]==target)
        {
            ansindex=mid;
            l=mid+1;
        }
        else
        {
            if(bin[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
    }
}

vector<int> searchrange(vector<int>&bin)
{
    int first=-1,second=-1,target=11;
    firstoccurence(bin,first,target);
    lastoccurence(bin,second,target);
    vector<int>range;
    range.push_back(first);
    range.push_back(second);
    return range;
}

int main()
{
    vector<int>binner{1,2,3,11,11,11,11,11,12};
    int firstindex=-1,target=11,secondindex=-1;
    firstoccurence(binner,firstindex,target);
    lastoccurence(binner,secondindex,target);
    cout<<firstindex<<"   "<<secondindex<<endl;

    vector<int>range=searchrange(binner);
    cout<<range[0]<<"   "<<range[1]<<endl;
    cout<<"total no of occurence is "<<range[1]-range[0]+1<<endl;
    
}
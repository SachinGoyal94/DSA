#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void checkOdd(int a)
{
    if(a%2!=0)
    {
        cout<<a<<endl;
    }
}
bool checkEven(int a)
{
    return a%2==0;
}
int main()
{
    vector<int>vect;
    vect.push_back(40);
    vect.push_back(35);
    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(50);
    vect.push_back(50);

    cout<<"for each algo to perform a function in a range of container"<<endl;
    for_each(vect.begin(),vect.end(),checkOdd);


    cout<<"find algo to find targeted element in a range of container"<<endl;
    int target=40;
    auto it=find(vect.begin(),vect.end(),target);
    cout<<*it<<endl;


    cout<<"find_if algo to return first element satisfying given condition"<<endl;
    auto kt=find_if(vect.begin(),vect.end(),checkEven);
    cout<<*kt<<endl; 


    cout<<"count returns no of times of occurence of an element in the container"<<endl;
    int ans=count(vect.begin(),vect.end(),target);
    cout<<ans<<endl;


    cout<<"count no of elements that satisfy given condition"<<endl;
    int counter=count_if(vect.begin(),vect.end(),checkEven);
    cout<<counter<<endl;


    cout<<"sort algo to sort given container"<<endl;
    sort(vect.begin(),vect.end());
    for(auto& a:vect)
    {
        cout<<a<<endl;
    }

    cout<<"to reverse elements in given container"<<endl;
    reverse(vect.begin(),vect.end());
    for(auto& a:vect)
    {
        cout<<a<<endl;
    }

    cout<<"to rotate the container"<<endl;
    rotate(vect.begin(),vect.begin()+1,vect.end());
    for(auto& a:vect)
    {
        cout<<a<<endl;
    }
    //left rotation by 1 
    //for right rotation vect.begin(),vect.begin()+vect.size()-(no of rotation),vect.end()

    cout<<"to remove duplicate using unique algo"<<endl;

    auto iterat=unique(vect.begin(),vect.end());
    vect.erase(iterat,vect.end());
    for(auto& a:vect)
    {
        cout<<a<<endl;
    }
    //here erase will only delete consecutive elements but due to rotate they become non concestive 
    //so either use it before rotate algo or use rotate like so to get proper functioning of erase and unique combo
    
    cout<<"to create a partition in container on the bases of a condition "<<endl;
    auto iterators=partition(vect.begin(),vect.end(),checkEven);
    for(auto& a:vect)
    {
        cout<<a<<endl;
    }


}
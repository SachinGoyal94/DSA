//char inbuilt functions not required 
//do string inbuilt functions 
#include<bits/stdc++.h>
using namespace std;

int main()
{
    char arr[100];
    cin.getline(arr,10);
    cout<<arr<<"   "<<arr[0]<<"   "<<(int)arr[0]<<endl;
    
    int u=arr[0];
    cout<<u<<endl;

    //lowercase to uppercase A->65 a->97
    for(int i=0;i<strlen(arr);i++)
    {
        char ch=arr[i];
        if(ch>='a' || ch<='z')
        {
            ch=ch-'a'+'A';
        }
        arr[i]=ch;
    }
    cout<<arr<<endl;

    //uppercase to lowercase A->65 a->97
    for(int i=0;i<strlen(arr);i++)
    {
        if(arr[i]>='A' || arr[i]<='Z')
        {
            arr[i]=arr[i]-'A'+'a';
        }
    }
    cout<<arr<<endl;

    char s[]="codewith";
        
    cout<<strlen(s)<<endl;//8
    cout<<sizeof(s);//9
}
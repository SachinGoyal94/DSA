#include<iostream>
using namespace std;


void pyramid(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout<<"   ";
        }
        for(int j=0;j<i+1;j++)
        {
            cout<<" * ";
        }
        for(int j=0;j<i;j++)
        {
            cout<<" * ";
        }
        cout<<endl;
    }
}

void ivtpyramid(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<"   ";
        }
        for(int j=0;j<n-i;j++)
        {
            cout<<" * ";
        }
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" * ";
        }
        cout<<endl;
    }
}

void Diamond(int n)
{
    pyramid(n);
    ivtpyramid(n);
}

void hllwpyramid(int n)
{
    int count=n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout<<"   ";
        }
        for(int j=0;j<1;j++)
        {
            cout<<" * ";
        }
        for(int j=0;j<i;j++)
        {
            cout<<"   ";
        }
        for(int j=0;j<i-1;j++)
        {
            cout<<"   ";
        }
        if(count>n-2)
        {
            for(int j=0;j<n-count;j++)
            {
                cout<<" * ";
            }
        }
        else{
            cout<<" * ";
        }
        count--;
        cout<<endl;
    }
}

void hllwivtpyramid(int n)
{
    int count=n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<"   ";
        }
        for(int j=0;j<1;j++)
        {
            cout<<" * ";
        }
        for(int j=0;j<n-i-1;j++)
        {
            cout<<"   ";
        }
        for(int j=0;j<n-i-2;j++)
        {
            cout<<"   ";
        }
        if(count==1)
        {
            for(int j=0;j<n-count-4;j++)
            {
                cout<<" * ";
            }
        }
        else
        {
            cout<<" * ";
        }
        count--;
        cout<<endl;
    }
} 

void hllwdiamond(int n)
{
    hllwpyramid(n);
    hllwivtpyramid(n);
}

void mixpyramid(int n)
{
   for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" * ";
        }
        for(int j=0;j<i+1;j++)
        {
            cout<<"   ";
        }
        for(int j=0;j<i;j++)
        {
            cout<<"   ";
        }
        
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" * ";
        }
        for(int j=0;j<i+1;j++)
        {
            cout<<"   ";
        }
        for(int j=0;j<i;j++)
        {
            cout<<"   ";
        }
        if(i!=4)
        {
            cout<<endl;
        }
    } 
}

void mixivtpyramid(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<" * ";
        }
        for(int j=0;j<n-i;j++)
        {
            cout<<"   ";
        }
        for(int j=0;j<n-i-1;j++)
        {
            cout<<"   ";
        }
        
        for(int j=0;j<i;j++)
        {
            cout<<" * ";
        }
        for(int j=0;j<n-i;j++)
        {
            cout<<"   ";
        }
        for(int j=0;j<n-i-1;j++)
        {
            cout<<"   ";
        }
        cout<<endl;
    }
}
void mixdiamond(int n)
{
    mixpyramid(n);
    mixivtpyramid(n);
}

void fancy(int n)
{
    int count =1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2*i+1;j++)
        {
            if(j%2==0)
            {
                cout<<count;
            }       
            else
            {
                cout<<" * ";
            }
        }
        count++;
        cout<<endl;
    }
}

void fullfancy(int n)
{
    fancy(n);
    
    int count=n-1;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<2*(n-i)-3;j++)
        {
            if(j%2==0)
            {
                cout<<count;
            }
            else{
                cout<<" * ";
            }
        }
        cout<<endl;
        count--;
    }
}

void ABCBA(int n) {
  for (int i = 0; i < n; i++) {
    char ch = 'A'; // ASCII 65 init.
    for (int j = 0; j < i + 1; j++) {
      cout << ch;
      ch++;
    }
    
    ch--;
    
    while (ch > 'A') {
      ch--;
      cout << ch;
    }
    cout << endl;
  }
}

int main()
{
    int n;
    cin>>n;
    //pyramid(n);
    
    //ivtpyramid(n);

    //Diamond(n);
    
    //hllwpyramid(n);

    //hllwivtpyramid(n);

    //hllwdiamond(n);

    //mixpyramid(n);

    //mixivtpyramid(n);

    //mixdiamond(n);

    //fancy(n);

    //fullfancy(n);

    //ABCBA(n);
}
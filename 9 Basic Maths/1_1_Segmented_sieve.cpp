//count prime no between [l,h] l,h belongs to integer
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
    //0 1 2 3Y 4N 5Y 6N 7Y 8N 9N 10N  
        int l=3,h=n;
        int a[n+1];
        for(int i =0; i<=n; i++){
            a[i] =1;
        }
        for(int i =2; i*i<=n; i++){
            for(int j =i*i; j<=n; j+=i){
                a[j] =0;
            }
        }
        int cnt =0;
        for(int i =l; i<n; i++){
            if(a[i]==1){
                cnt++;
            }
        }
        
        return cnt;
    }
};
int main()
{
    Solution s;
    cout<<s.countPrimes(10);
}

//TC=O(n*log(log(n)))
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
    //0 1 2 3Y 4N 5Y 6N 7Y 8N 9N 10N    
        int a[n+1];
        for(int i =0; i<=n; i++){
            a[i] =1;
        }
        for(int i =2; i*i<=n; i++){
            for(int j =i+i; j<=n; j+=i){
                a[j] =0;
            }
        }
        int cnt =0;
        for(int i =6; i<n; i++){
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
//ok
/*
#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<char>> ZigZag(const std::string& s, int numrows) {
    if (numrows == 1 || numrows >= s.length()) {
        std::vector<std::vector<char>> arr(1, std::vector<char>(s.length()));
        for (int i = 0; i < s.length(); ++i) {
            arr[0][i] = s[i];
        }
        return arr;
    }

    std::vector<std::vector<char>> arr(numrows, std::vector<char>(s.length(), ' '));
    int i = 0, j = 0, index = 0;
    bool goingDown = true;

    while (index < s.length()) {
        arr[i][j] = s[index++];
        if (goingDown) {
            if (i == numrows - 1) {
                goingDown = false;
                j++;
            } else {
                i++;
            }
        } else {
            if (i == 0) {
                goingDown = true;
                j++;
            } else {
                i--;
                j++;
            }
        }
    }

    return arr;
}

int main() {
    std::string g = "PA";
    std::vector<std::vector<char>> arr = ZigZag(g, 4);
    for (int m = 0; m < arr.size(); m++) {
        for (int n = 0; n < arr[m].size(); n++) {
            std::cout << arr[m][n] << "    ";
        }
        std::cout << std::endl;
    }
    return 0;
}*/
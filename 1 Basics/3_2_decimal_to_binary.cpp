#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 96455;
    string binary = "";

    while(n)
    {
        int bit = (n & 1);
        binary = (bit ? "1" : "0") + binary;
        n = n >> 1;
    }

    cout << "Binary representation: " << binary << endl;

    int k = 1101, j = 0, decimal = 0; 
    while (k) 
    {
        int bit = k % 10;
        decimal = decimal + bit * pow(2, j++);
        k = k / 10;
    }

    std::cout << "The decimal equivalent is: " << decimal << std::endl;

    return 0;
}
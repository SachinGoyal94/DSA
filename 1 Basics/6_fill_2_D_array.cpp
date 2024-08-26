#include<iostream>
#include<algorithm> 
using namespace std;
int main()
{
    int arr[2][3]; 
    cout << "Before filling" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " "; // print uninitialized values
        }
        cout << endl;
    }

    cout << "after filling" << endl;
    for (int i = 0; i < 2; i++) {
        fill(&arr[i][0], &arr[i][3], 23); // fill each row with 23
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " "; // print filled values
        }
        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int sum;
    int left;
    int right;
} SubarrayResult;

SubarrayResult maxCrossingSum(int arr[], int low, int mid, int high) {
    SubarrayResult result;
    result.sum = INT_MIN;
    int left_sum = INT_MIN, right_sum = INT_MIN;
    int sum = 0;
    
    // Calculate maximum left sum and its starting index
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
            result.left = i;
        }
    }
    
    sum = 0;
    // Calculate maximum right sum and its ending index
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
            result.right = i;
        }
    }
    
    result.sum = left_sum + right_sum;
    return result;
}

SubarrayResult maxSubArraySum(int arr[], int low, int high) {
    SubarrayResult result;
    
    // Base case: when there's only one element
    if (low == high) {
        result.sum = arr[low];
        result.left = result.right = low;
        return result;
    }
    
    int mid = (low + high) / 2;
    
    // Recursive calls for left, right, and crossing subarrays
    SubarrayResult left_result = maxSubArraySum(arr, low, mid);
    SubarrayResult right_result = maxSubArraySum(arr, mid + 1, high);
    SubarrayResult crossing_result = maxCrossingSum(arr, low, mid, high);
    
    // Return the maximum of three results
    if (left_result.sum >= right_result.sum && left_result.sum >= crossing_result.sum) {
        return left_result;
    } 
    else if (right_result.sum >= left_result.sum && right_result.sum >= crossing_result.sum) {
        return right_result;
    } 
    else {
        return crossing_result;
    }
}



int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    SubarrayResult result = maxSubArraySum(arr, 0, n - 1);
    
    printf("Maximum subarray sum is: %d\n", result.sum);
    printf("Subarray indices are: (%d, %d)\n", result.left, result.right);
    printf("Subarray: ");
    for (int i = result.left; i <= result.right; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

/*
class Solution {
public:
    int findPeakElement(vector<int>& arr) 
    {
        int s = 0, e = arr.size() - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] > arr[mid + 1]) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
    
};
*/
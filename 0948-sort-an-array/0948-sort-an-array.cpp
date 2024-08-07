class Solution {
public:
    void mergeSort(vector<int> &arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
    
    void merge(vector<int> &arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> L(n1);
        vector<int> R(n2);
        
        for (int i = 0; i < n1; ++i)
            L[i] = arr[left + i];
        for (int i = 0; i < n2; ++i)
            R[i] = arr[mid + 1 + i];
        
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                ++i;
            } else {
                arr[k] = R[j];
                ++j;
            }
            ++k;
        }
        
        while (i < n1) {
            arr[k] = L[i];
            ++i;
            ++k;
        }
        
        while (j < n2) {
            arr[k] = R[j];
            ++j;
            ++k;
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

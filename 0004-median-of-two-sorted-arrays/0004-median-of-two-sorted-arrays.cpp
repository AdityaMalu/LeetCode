class Solution {
public:
    double kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k) {
        if (n > m) {
            return kthElement(arr2, arr1, m, n, k);
        }

        int low = max(0, k - m), high = min(k, n);

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
            int right1 = (cut1 == n) ? INT_MAX : arr1[cut1];
            int right2 = (cut2 == m) ? INT_MAX : arr2[cut2];

            if (left1 <= right2 && left2 <= right1) {
                return max(left1, left2);
            } else if (left1 > right2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }

        return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m = nums2.size();
        if((n+m)%2==1){
            return kthElement(nums1,nums2,n,m,(n+m)/2+1);
        }
        else{
            return (kthElement(nums1,nums2,n,m,(n+m)/2)+kthElement(nums1,nums2,n,m,((n+m)/2)+1))/2;
        }

        
    }
};
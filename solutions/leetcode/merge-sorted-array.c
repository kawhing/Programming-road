void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    nums1Size = m + n;
    nums2Size = n;

    for (int i = m; i < nums1Size; ++i) {
        nums1[i] = nums2[i - m];
    }

    for (int i = 1; i < nums1Size; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums1[i] < nums1[j]){
                int tmp = nums1[i];
                for (int k = i-1; k >= j; --k){
                    nums1[k+1] = nums1[k];
                }
                nums1[j] = tmp;
            }
        }
    }
    
}
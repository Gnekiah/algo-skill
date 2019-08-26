double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int numsSize = nums1Size + nums2Size;
    int nums[numsSize];
    double ret = 0;
    
    for (int i=0, j=0; i+j < numsSize; ) {
        if (i == nums1Size) {
            while (j < nums2Size) {
                nums[i+j] = nums2[j];
                j++;
            }
            break;
        }
        if (j == nums2Size) {
            while (i < nums1Size) {
                nums[i+j] = nums1[i];
                i++;
            }
            break;
        }
        if (nums1[i] < nums2[j]) {
            nums[i+j] = nums1[i];
            i++;
        } else {
            nums[i+j] = nums2[j];
            j++;
        }
    }
    ret = (double)(nums[numsSize/2] + nums[(numsSize-1)/2]) / 2.0;
    return ret;
}

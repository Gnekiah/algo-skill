/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * Example 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 */

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

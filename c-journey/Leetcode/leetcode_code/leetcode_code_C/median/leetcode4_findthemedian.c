#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // 确保 nums1 是较短的数组，这样 i 的搜索范围小，且 j 不会越界
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int m = nums1Size;
    int n = nums2Size;
    int left = 0, right = m;
    
    while (left <= right) {
        // i: nums1 左边元素的个数
        // j: nums2 左边元素的个数
        int i = (left + right) / 2;
        int j = (m + n + 1) / 2 - i;//加一直接把奇数情况表示为左边的最大值
        
        // 处理边界：如果切割点在边缘，用极大/极小值代替
        int nums1LeftMax  = (i == 0) ? -10000000 : nums1[i - 1];
        int nums1RightMin = (i == m) ? 10000000  : nums1[i];
        int nums2LeftMax  = (j == 0) ? -10000000 : nums2[j - 1];
        int nums2RightMin = (j == n) ? 10000000  : nums2[j];
        
        // 检查是否满足：左边所有元素 <= 右边所有元素
        if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) 
        {
            // 找到正确切割！
            if ((m + n) % 2 == 1)
            {
                // 总长度奇数：中位数就是左边最大值
                int maxLeft = nums1LeftMax > nums2LeftMax ? nums1LeftMax : nums2LeftMax;
                return maxLeft;
            } 
            else 
            {
                // 总长度偶数：(左边最大 + 右边最小) / 2
                int maxLeft = nums1LeftMax > nums2LeftMax ? nums1LeftMax : nums2LeftMax;
                int minRight = nums1RightMin < nums2RightMin ? nums1RightMin : nums2RightMin;
                return (maxLeft + minRight) / 2.00000;
            }
        } 
        // nums1 左边太大，切割点左移
        else if (nums1LeftMax > nums2RightMin) {
            right = i - 1;
        } 
        // nums1 左边太小，切割点右移
        else {
            left = i + 1;
        }
    }
    
    return 0.0; // 理论上不会执行到这里
}

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    printf("%.5f\n", findMedianSortedArrays(nums1, 2, nums2, 1));  // 2.00000
    
    int nums3[] = {1, 2};
    int nums4[] = {3, 4};
    printf("%.5f\n", findMedianSortedArrays(nums3, 2, nums4, 2));  // 2.50000
    
    return 0;
}
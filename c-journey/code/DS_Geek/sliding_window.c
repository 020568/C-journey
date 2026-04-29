#include <stdio.h>
#include <stdlib.h>

/**
 * Function to find the maximum sum of k consecutive elements.
 * @param arr: The input array
 * @param n: Total number of elements in the array
 * @param k: The size of the sliding window
 * @return: The maximum sum found, or -1 if the input is invalid
 */
int maxSum(int arr[], int n, int k) {
    // Check if the window size k is valid relative to array size n
    if (n < k) {
        printf("Invalid: Array size is smaller than window size.\n");
        return -1;
    }

    // Compute the sum of the first window of size k
    int max_sum = 0;
    for (int i = 0; i < k; i++) {
        max_sum += arr[i];
    }

    // Compute sums of the remaining windows by sliding the window.
    // We subtract the element that is leaving the window (arr[i-k])
    // and add the new element entering the window (arr[i]).
    int window_sum = max_sum;
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        
        // Update max_sum if the current window_sum is larger
        if (window_sum > max_sum) {
            max_sum = window_sum;
        }
    }

    return max_sum;
}

int main() {
    // Initialize the array and its parameters
    int arr[] = {5, 2, -1, 0, 3};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    // Calculate and print the result
    int result = maxSum(arr, n, k);
    
    if (result != -1) {
        printf("Maximum sum of %d consecutive elements: %d\n", k, result);
    }

    return 0;
}
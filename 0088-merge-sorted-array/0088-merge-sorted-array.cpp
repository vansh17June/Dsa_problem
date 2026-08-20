class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result(m + n);  // Create a temporary vector to store merged result
        int i = 0, j = 0, k = 0;     // i for nums1 index, j for nums2 index, k for result index

        // Merge the two arrays while both have elements left
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                result[k] = nums1[i];
                i++;
            } else {
                result[k] = nums2[j];
                j++;
            }
            k++;
        }

        // If there are remaining elements in nums1, append them to result
        while (i < m) {
            result[k] = nums1[i];
            i++;
            k++;
        }

        // If there are remaining elements in nums2, append them to result
        while (j < n) {
            result[k] = nums2[j];
            j++;
            k++;
        }

        // Copy the merged result back to nums1
        for (i = 0; i < m + n; i++) {
            nums1[i] = result[i];
        }
    }
};

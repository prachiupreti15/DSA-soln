class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int a = nums1.size() - 1;

        if (m == 0) {
            for (int k = 0; k < n; k++)
                nums1[k] = nums2[k];
            return;
        }

        int i = m - 1;
        int j = n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[a] = nums1[i];
                i--;
                a--;
            }

            else if (nums2[j] > nums1[i]) {
                nums1[a] = nums2[j];
                j--;
                a--;
            }
        }
        while (j >= 0) {
            nums1[a] = nums2[j];
            j--;
            a--;
        }
    }
};
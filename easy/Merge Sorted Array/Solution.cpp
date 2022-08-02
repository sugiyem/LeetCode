class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = m - 1, index2 = n - 1, ansIndex = m + n - 1;
        
        while(index1 >= 0 && index2 >= 0) {
            if (nums1[index1] >= nums2[index2]) {
                nums1[ansIndex--] = nums1[index1--];
            } else {
                nums1[ansIndex--] = nums2[index2--];
            }
        }
        
        while(index2 >= 0) {
            nums1[ansIndex--] = nums2[index2--];
        }
    }
};
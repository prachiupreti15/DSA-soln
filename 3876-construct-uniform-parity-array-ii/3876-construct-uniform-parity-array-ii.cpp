class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        // sort(nums1.begin(), nums1.end());

        if(*min_element(nums1.begin(), nums1.end()) % 2 == 1) return true;

        for(int i : nums1){
            if(i % 2 != 0){
                return false;
            }
        }
        return true;
    }
};
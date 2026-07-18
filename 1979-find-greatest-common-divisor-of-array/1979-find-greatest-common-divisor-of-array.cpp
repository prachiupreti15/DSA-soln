class Solution {
public:
    int findGCD(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) return nums[0];
        sort(nums.begin() , nums.end());

        return gcd(nums[0] , nums[n-1]);

    }
};
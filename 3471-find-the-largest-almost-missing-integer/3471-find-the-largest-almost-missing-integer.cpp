class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();

        if (k == n)
            return *max_element(nums.begin(), nums.end());

        unordered_map<int, int> freq;

        for (auto x : nums) {
            freq[x]++;
        }
        if (k == 1) {
            int ans = -1;

            for (auto it : freq) {
                if (it.second == 1) {
                    ans = max(ans, it.first);
                }
            }

            return ans;
        }

        if (k > 0 && k < n) {
            if (freq[nums[0]] == 1 && freq[nums[n - 1]] == 1)
                return max(nums[0], nums[n - 1]);

            else if (freq[nums[0]] == 1 && freq[nums[n - 1]] > 1)
                return nums[0];

            else if ((freq[nums[0]] > 1 && freq[nums[n - 1]] == 1))
                return nums[n - 1];

            else
                return -1;
        }
        return -1;
    }
};
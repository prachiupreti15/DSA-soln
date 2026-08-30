class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        int minidx = -1, maxidx = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == mini)
                minidx = i + 1;

            if (nums[i] == maxi)
                maxidx = i + 1;
        }

        int left = min(minidx, maxidx);
        int right = max(minidx, maxidx);

        int ans = right;

        ans = min(ans, n - left + 1);

        ans = min(ans, left + n - right + 1);

        return ans;
    }
};
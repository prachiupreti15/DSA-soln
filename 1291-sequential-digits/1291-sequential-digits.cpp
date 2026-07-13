class Solution {
public:
    set<long long> nums;
    vector<int> ans;

    void generate(int arr[], int n, int idx, long long current) {
        if (idx == n)
            return;

        current = current * 10 + arr[idx];
        nums.insert(current);

        generate(arr, n, idx + 1, current);
    }

    vector<int> sequentialDigits(int low, int high) {
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int n = sizeof(arr) / sizeof(arr[0]);

        for (int i = 0; i < n; i++) {
            generate(arr, n, i, 0);
        }

        for (auto x : nums) {
            if (x >= low && x <= high)
                ans.push_back(x);
        }

        return ans;
    }
};
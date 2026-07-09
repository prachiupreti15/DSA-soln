class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& candidates, int target, vector<int>& cur, int i) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }

        if (target < 0 || i >= candidates.size()) {
            return;
        }

        cur.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], cur, i + 1); 
        cur.pop_back();

        while (i + 1 < candidates.size() &&
               candidates[i] == candidates[i + 1]) {
            i++;
        }

        backtrack(candidates, target, cur, i + 1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<int> cur;
        backtrack(candidates, target, cur, 0);

        return ans;
    }
};
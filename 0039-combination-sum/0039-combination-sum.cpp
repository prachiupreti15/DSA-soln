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
        backtrack(candidates, target - candidates[i], cur, i);
        cur.pop_back();
        backtrack(candidates, target, cur, i + 1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> cur;
        backtrack(candidates, target, cur, 0);
        return ans;
        
    }
};
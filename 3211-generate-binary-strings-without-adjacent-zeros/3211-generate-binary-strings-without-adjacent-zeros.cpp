class Solution {
public:

    vector<string> ans;

    void solve(int n, string &curr) {
        
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        curr.push_back('1');
        solve(n, curr);
        curr.pop_back();

        if (curr.empty() || curr.back() == '1') {
            curr.push_back('0');
            solve(n, curr);
            curr.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        string curr = "";
        solve(n, curr);
        return ans;
    }
};
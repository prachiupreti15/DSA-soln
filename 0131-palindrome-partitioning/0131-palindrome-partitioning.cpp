class Solution {
public:
    
    vector<vector<string>> ans;

    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void backtrack(int i, int j, vector<string> &curr, string &s) {
        if (i >= s.length()) {
            if (i == j) {
                ans.push_back(curr);
            }
            return;
        }

        if (isPalindrome(s, j, i)) {   
            curr.push_back(s.substr(j, i - j + 1));
            backtrack(i + 1, i + 1, curr, s);
            curr.pop_back();
        }

        backtrack(i + 1, j, curr, s);
    }

    vector<vector<string>> partition(string s) {
        vector<string> curr;
        backtrack(0, 0, curr, s);
        return ans;
    }
};
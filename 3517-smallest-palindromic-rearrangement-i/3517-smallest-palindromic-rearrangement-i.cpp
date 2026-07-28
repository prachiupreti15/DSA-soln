class Solution {
public:
    string smallestPalindrome(string s) {

        int n = s.length();
        if (n == 1)
            return s;

        map<char, int> freq;

        for (auto x : s) {
            freq[x]++;
        }

        string ans = "";
        char single = '\0';

        for (auto it : freq) {
            if (it.second % 2 == 0) {
                int cnt = it.second / 2;
                while (cnt--) {
                    ans.push_back(it.first);
                }
            } else {
                int cnt = it.second / 2;
                while (cnt--) {
                    ans.push_back(it.first);
                }
                single = it.first;
            }
        }

        int m = ans.length();

        if (single != '\0')
            ans.push_back(single);

        for (int i = m - 1; i >= 0; i--) {
            ans.push_back(ans[i]);
        }

        return ans;
    }
};
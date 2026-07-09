class Solution {
public:

    vector<string> ans;

    vector<string> digitToChar = {"", "", "abc", "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(int i , string curr , string digits){

        if (i == digits.length()) { 
            ans.push_back(curr);
            return ;
        }

        string chars = digitToChar[digits[i] - '0'];
        for (char c : chars) {
            backtrack(i + 1, curr + c, digits);
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty()) return {}; 

        backtrack(0, "", digits);
        return ans;
    }
};
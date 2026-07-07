class Solution {
public:
    long long sumAndMultiply(int n) {

        int sum = 0;
        string num = "";

        string s = to_string(n);

        for (char x : s) {
            if (x != '0') {
                num += x;          
                sum += x - '0';    
            }
        }

        if (num.empty())
            return 0;
            
        int ans = stoi(num);
        return 1LL * ans * sum;
    }
};
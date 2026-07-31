class Solution {
public:
    int minimumPushes(string word) {

        int n = word.length();
        int ans = 0;
        unordered_map<char, int> freq;

        for (auto x : word) {
            freq[x]++;
        }

        vector<pair<char, int>> v(freq.begin(), freq.end());

        sort(v.begin(), v.end(), [](const auto& p1, const auto& p2) {
            return p1.second > p2.second;
        });

        for ( int i = 0 ; i < v.size() ; i++ ){
            ans += v[i].second*((i/8)+1);
        }
        return ans;
    }
};
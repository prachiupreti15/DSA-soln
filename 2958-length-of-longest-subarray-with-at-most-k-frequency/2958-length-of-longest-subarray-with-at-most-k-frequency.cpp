class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int n = nums.size();
        int ans = 0;
        int currans = 0;

        unordered_map<int , int> freq;

        int i = 0 ;
        int j = 0 ;

        while ( i < n && j < n ){
            if (freq[nums[j]] < k) {
                freq[nums[j]]++;
                j++;
                currans++;
                ans = max(currans , ans);
            }
            else if(freq[nums[j]] >= k){
                while(freq[nums[j]] >= k){
                    freq[nums[i]]--;
                    i++;
                    currans--;
                }
            }
        }
        return ans;
    }
};
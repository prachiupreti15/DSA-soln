class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        int pointer = -1;
        int shift = n-1 ;

        if (n==0) return 0;

        int i = 0 ;
        while ( i < n ){
            if (nums[i] == val && i != pointer){
                swap(nums[i] , nums[shift]);
                pointer = shift;
                shift--; 
                i--;            
            }
            i++ ;
            if (i == pointer) break;
        }
        if (pointer == -1) return n;
        return pointer;
    }
};
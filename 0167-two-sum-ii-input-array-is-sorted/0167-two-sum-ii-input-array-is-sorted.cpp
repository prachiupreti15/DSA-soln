class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size() ;

        vector <int> ans;

        int left = 0 ;
        int right = n-1 ;

        bool found = false ;

        while ( found == false ){
            if (numbers[left] + numbers[right] == target){
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                found = true ;
            }

            else if (numbers[left] + numbers[right] < target){
                left++ ;
            }
            
            else 
                right-- ;
        }
        return ans;
    }
};
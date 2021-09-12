class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!nums.size()) return {-1, -1};
        
        int L = 0, R = nums.size() - 1;
        while(L < R){
            int mid = (L+R)/2;
            if(nums[mid] < target){
                L = mid + 1;
            }else if(nums[mid] > target){
                R = mid - 1;
            }else{
                if(nums[L] != target) L++;
                if(nums[R] != target) R--;
                if(nums[L] == target && nums[R] == target) break;
            }
            
        }       
        
        if(nums[L] != target){
            L = -1;
            R = -1;
        }
        
        return {L, R};
    }
};
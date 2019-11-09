/*
Method: Binary Search, mainly consider three cases:
        case 1: array is purely ascending, use Binary Search directly
        case 2: array is rotated and our target should in the left part of array
        case 3: array is rotated and our target should in the right part of array

Time: O(logn)
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // special cases
        if(!nums.size()) return -1;
        if(nums.size() == 1) return nums[0] == target ? 0:-1;
   
        int L = 0, R = nums.size()-1;
        while(L <= R){
            int mid = L + (R-L)/2;
            if(nums.front() < nums.back()){
                // pure ascending array
                if(nums[mid] == target){
                    return mid;
                }else if(nums[mid] > target){
                    R = mid - 1;
                }else{
                    L = mid + 1;
                }
            }
            else if(target >= nums[0]){
                // target in left part
                if(nums[mid] == target){
                    return mid;
                }else if(nums[mid] > target || nums[mid] < target && nums[mid] <= nums.back()){
                    R = mid - 1;
                }else{
                    L = mid + 1;
                }
            }else{
                // target in right part
                if(nums[mid] == target){
                    return mid;
                }else if(nums[mid] > target && nums[mid] <= nums.back()){
                    R = mid - 1;      
                }else{
                    L = mid + 1;
                }
            } 
        }
        return -1;
    }
};
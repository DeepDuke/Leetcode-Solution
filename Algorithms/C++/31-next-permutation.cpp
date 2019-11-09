/*
Method: simuate the permutation process
Time: O(n)
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2, j = nums.size() - 1;
        while(i >= 0 && nums[i] >= nums[i+1]) i--;
        if(i >= 0){
            while(j >= 0 && nums[j] <= nums[i]) j--;
            swap(nums[j], nums[i]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};
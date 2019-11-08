/*
Method: binary search, 先固定第一个数，然后用二分法去逼近target来寻找另外两个数，
在逼近过程中遇到的所有两个数的组合加上第一个数的和都有可能是最接近target的情况，因此对
逼近过程中的每个组合都要做判断。
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minDiff = 0x7FFFFFFF;
        int minSum = 0;
        for(int i = 0; i < nums.size()-2; i++){
            int L = i+1, R = nums.size()-1;
            while(L < R){
                int sum = nums[i] + nums[L] + nums[R];
                if(abs(sum - target) < minDiff){
                    minDiff = abs(sum - target);
                    minSum = sum;
                }
                if(sum < target){
                    L++;
                }else if(sum > target){
                    R--;
                }else{
                    break;
                }
            }
        }
        return minSum;
    }
};
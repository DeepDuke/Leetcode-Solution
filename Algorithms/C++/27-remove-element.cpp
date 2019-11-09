/*
Method: two  pointers
Time: O(n)
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p = 0, cnt = 0;
        while(p < nums.size() && nums[p] != val ) {
            p++;
            cnt++;
        }
        for(int q = p+1; q < nums.size(); q++){
            if(nums[q] != val) {
                nums[p++] = nums[q];
                cnt++;
            }
        }
        return cnt;
    }
};
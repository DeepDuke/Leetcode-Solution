/*
Method: two pointers, one points to the pos of the last unique element, 
the other points to the current element.

Time: O(n)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // special cases 
        if(nums.size() < 2) return nums.size();
        int cnt = 1;
        for(int p = 0, q = 1; q < nums.size(); q++){
            if(nums[p] == nums[q]) {
                continue;
            }
            cnt++;
            nums[++p] = nums[q];
        }
        return cnt;
    }
};
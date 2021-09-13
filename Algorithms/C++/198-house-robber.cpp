class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        vector<int> table(nums.size());
        table[0] = nums[0], table[1] = max(nums[0], nums[1]);
        
        for(int i = 2;  i < table.size(); ++i){
            // select nums[i] OR not select  nums[i]
            table[i] = max(table[i-1], table[i-2]+nums[i]);
        }
        
        return table[table.size()-1]; 
    }
};
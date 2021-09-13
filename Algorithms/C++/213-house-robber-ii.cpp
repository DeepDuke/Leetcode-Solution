class Solution {
public:
   
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        // Select to rob first house
        vector<int> T(n-1);
        T[0] = nums[0], T[1] = nums[0];
        for(int i = 2; i < n-1; ++i){
            T[i] = max(T[i-1], T[i-2]+nums[i]);
        }
        
        // Select not to rob first house
        vector<int> S(n);
        S[0] = 0, S[1] = nums[1];
        for(int i = 2; i < n; ++i){
            S[i] = max(S[i-1], S[i-2]+nums[i]);
        }
        
        return max(T[n-2], S[n-1]);        
    }
};
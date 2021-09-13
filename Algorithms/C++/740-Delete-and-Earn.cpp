/*
Method: Convert this problem to House Robber Problem
Time Complexity: O(n)
*/
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> hash(10010, 0);
        for(int i = 0; i < nums.size(); i++){
            hash[nums[i]] += nums[i];
        }
        
        // dp
        vector<int> T(hash.size());
        T[0] = hash[0], T[1] = max(hash[0], hash[1]);
        for(int i = 2; i < T.size(); ++i){
            T[i] = max(T[i-1], T[i-2]+hash[i]);
        }
        
        return T[T.size()-1];
    }
};
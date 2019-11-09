/*
Method: kSum general solution --> convert ksum into k-1 sum subproblem
until k equals 2 which can be solved by two pointers. And use pruning to 
save time;
Time: O(n^2*logn) on average time
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        // special cases
        if(nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        return kSum(nums,  0, nums.size()-1, 4, target);
    }
private:
    vector<vector<int>> kSum(vector<int>& nums, int L, int R, int k, int target){
        vector<vector<int>> ans;
        if(k == 2){
            int p = L, q = R;
            while(p < q){
                int sum = nums[p] + nums[q];
                if(sum < target){
                    p++;
                }else if(sum > target){
                    q--;
                }else{
                    vector<int> v = {nums[p], nums[q]};
                    ans.push_back(v);
                    // skip the duplication
                    p++; q--;
                    while(p < q && nums[p] == nums[p-1]) p++;
                    while(p < q && nums[q] == nums[q+1]) q--;
                }
            }
        }else{
            for(int i = L; i <= R-k+1; i++){
                // skip the duplication
                if(i > L && nums[i] == nums[i-1]) continue;
                // prune
                int sum = 0;
                for(int j = i; j <= i+k-1; j++) sum += nums[j];
                if(sum > target) break;
                sum = nums[i];
                for(int j = R; j > R-k+1; j--) sum += nums[j];
                if(sum < target) continue;
                // convert into k-1 scope subproblem
                vector<vector<int>> tmp = kSum(nums, i+1, R, k-1, target-nums[i]);
                for(auto& v: tmp) v.insert(v.begin(), nums[i]);
                ans.insert(ans.end(), tmp.begin(), tmp.end());
            }
        }
        return ans;
    }
};
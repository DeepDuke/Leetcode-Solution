/*
Method 1: use Binary Search, sort the array for skipping the duplication and set the first number as nums[i], 
then use binary search to find the other two numers whose sum is -nums[i];

Time: average O(nlogn)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        // special cases
        if(nums.size() == 0 || nums.size() == 1 || nums.size() == 2) return ans;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            // skip the duplication
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int L = i+1, R = nums.size() - 1;
            while(L < R){
                if(nums[i] + nums[L] + nums[R] < 0){
                    L++;
                }else if(nums[i] + nums[L] + nums[R] > 0){
                    R--;
                }else{
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[L]);
                    v.push_back(nums[R]);
                    ans.push_back(v);
                    // skip the duplication
                    L++; R--;
                    while(L < R && nums[L] == nums[L-1]) L++;
                    while(L < R && nums[R] == nums[R+1]) R--;
                }
            }
        }
        return ans;
    }
};
/*
Improvement for more general cases: Suppose we want to find k numbers whose sum is target, then we can set the first number A fixed, 
then convert the k scope problem into k-1 scope problem that we need to find k-1 numbers whose sum is target - A until k == 2 where we 
can solve that problem easily.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // special cases
        vector<vector<int> > ans;
        if(nums.size() == 0 || nums.size() == 1 || nums.size() == 2) return ans;
        
        sort(nums.begin(), nums.end());
        return kSum(nums, 0, nums.size()-1, 3, 0);
    }
private:
    vector<vector<int> > kSum(vector<int>& nums, int L, int R, int k, int target){
        vector<vector<int> > ans;
        if(k == 2){
            int p = L, q = R;
            while(p < q){
                if(nums[p] + nums[q] < target){
                    p++;
                }else if(nums[p] + nums[q] > target){
                    q--;
                }else{
                    vector<int> v;
                    v.push_back(nums[p]); v.push_back(nums[q]);
                    ans.push_back(v);
                    //  skip the duplication
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
                // convert into  k-1 scope problem 
                vector<vector<int> > tmp = kSum(nums, i+1, R, k-1, target-nums[i]);
                for(auto &v: tmp) v.insert(v.begin(), nums[i]);
                ans.insert(ans.end(), tmp.begin(), tmp.end());
            }
        }
        return ans;
    }
};
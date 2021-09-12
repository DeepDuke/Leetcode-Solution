class Solution {
public:
    vector<vector<int>> solutions;
    vector<int> sol;
    
    void solve(vector<int>& candidates, int target, int idx){
        if(!candidates.size()) return;
        if(idx == candidates.size())
        {
            if(target == 0) 
            {
                solutions.push_back(sol);
            }
            return;
        }
        
        // select idx 
        if(candidates[idx] <= target)
        {
            sol.push_back(candidates[idx]);
            solve(candidates, target - candidates[idx], idx);
            sol.pop_back();
        }
        // donot select idx
        solve(candidates, target, idx+1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0);
        return solutions;
    }
};
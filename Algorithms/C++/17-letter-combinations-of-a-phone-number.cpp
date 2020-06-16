// This is simply just a recursion problem. No backtracking exists.
class Solution {
public:
    vector<string> res;
    unordered_map<char, string> mp;
    
    void func(string combination, string digits){
        if(digits.size() == 0){
            res.push_back(combination);
            return;
        }
        for(auto c: mp[digits[0]]){
            func(combination+c, digits.substr(1));
        }
    }
    vector<string> letterCombinations(string digits) {
        // special case
        if(!digits.size()) return res;
        // init mp
        mp['2']="abc"; mp['3']="def"; mp['4']="ghi"; mp['5']="jkl";
        mp['6']="mno"; mp['7']="pqrs"; mp['8']="tuv"; mp['9']="wxyz";
        
        func("", digits);
        return res;        
    }
};
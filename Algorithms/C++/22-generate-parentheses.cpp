class Solution {
public:
    vector<string>  res;
    
    void dfs(int maxInNum, int inNum, int outNum, string str){
        if(outNum == maxInNum) {
            res.push_back(str);
            return;
        }
        if(inNum < maxInNum) dfs(maxInNum, inNum+1, outNum, str+'(');
        if(outNum < inNum) dfs(maxInNum, inNum, outNum+1, str+')');
    }
   
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return res;
    }
};
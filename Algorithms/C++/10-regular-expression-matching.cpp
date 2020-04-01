// Solution 1 Top down
class Solution {
public:
    bool isMatch(string s, string p) {
        // recursion method
        if(p.size() == 0){
            if(s.size() == 0) return true;
            else return false;
        }
        
        bool firstMatch = false;
        if(s.size() != 0 && (p[0] == '.' || s[0] == p[0])){
            firstMatch = true;
        }
        if(p.size() >= 2 && p[1] == '*'){
            return isMatch(s, p.substr(2)) || firstMatch && isMatch(s.substr(1), p);
        }else{
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};

// Solution 2 Bottom up
class Solution {
public:
    bool isMatch(string s, string p) {
        // dp method
        vector<vector<bool> > dp(s.size()+1, vector<bool>(p.size()+1, 0));
        dp[s.size()][p.size()] = true;  // matched
        
        for(int i = s.size(); i >= 0;  i--){
            for(int j = p.size()-1; j >= 0; j--){
                bool firstMatch = false;
                if(i < s.size() && (p[j] == '.' || p[j] == s[i])){
                    firstMatch = true;
                }
                if(j+1 < p.size() && p[j+1] == '*'){
                    dp[i][j] = dp[i][j+2] || firstMatch && dp[i+1][j];
                }else{
                    dp[i][j] = firstMatch && dp[i+1][j+1];
                }
                //cout << "(" << i << ","  << j << "):\t" << dp[i][j] << endl; 
            }
        }
        return dp[0][0];
    }
};
/*
Dynamic Programming
Time Complexity: O(n)
Space Complexity: O(n) 
*/
class Solution {
public:
    string longestPalindrome(string s) {
        // special cases
        if(s == "") return s;
        
        vector<vector<int> > dp(s.size(), vector<int>(s.size(), 0));
        int maxLen = 1;
        int startPos = 0;
        // L = 1
        for(int i = 0; i < s.size(); i++){
            dp[i][i] = 1;
        }
        // L = 2
        for(int i = 0; i < s.size()-1; i++){
            if(s[i] == s[i+1]){
                maxLen = 2;
                startPos = i;
                dp[i][i+1] = 1;
            }
        }
        // L >= 3
        for(int L = 3; L <= s.size(); L++){
            for(int i = 0; i + L - 1 < s.size(); i++){
                int j = i+L-1;
                if(s[i] == s[j] && dp[i+1][j-1] == 1){
                    dp[i][j] = 1;
                    maxLen = L;
                    startPos = i;
                }
            }
        }
        // find substr
        return s.substr(startPos, maxLen);
    }
};
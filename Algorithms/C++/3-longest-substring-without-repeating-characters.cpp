/*
Method 1: two pointers, use two pointers i, j to stand for a sliding window [i, j) which is
a substr with no duplicates characters in it. When s[j] occurs at pos in s[i, j), change sliding 
window's start from i to i+pos+1.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        int i = 0, j = 1, maxLen = 0;
        while(j < s.size()){
            string tmp = s.substr(i, j-i);  // s[i] to  s[j-1]
            int pos = tmp.find(s[j]);
            if(pos != string::npos){
                // found s[j] in tmp
                maxLen = max(maxLen, j-i);
                i = i + pos + 1;
            }
            j++;
        }
        maxLen = max(maxLen, j-i);
        return maxLen;
    }
};
/*
Method 2: use a hash table to store a character's last occurence position 
to indicate whether a character has appeared or not.
Time: O(n)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, start = 0;
        vector<int> hash(256, -1);
        for(int end = 0; end < s.size(); end++){
            if(hash[s[end]] != -1){
                // appeared before
                start = max(start, hash[s[end]]+1);
            }
            maxLen = max(maxLen, end-start+1);
            hash[s[end]] = end;
        }
        return maxLen;
    }
};
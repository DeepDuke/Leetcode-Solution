// Solution 1
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

// Solution 2

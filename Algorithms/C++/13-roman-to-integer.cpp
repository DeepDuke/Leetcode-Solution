class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        unordered_map<char, int> trans;
        trans['I'] = 1; trans['V'] = 5; trans['X'] = 10;
        trans['L'] = 50; trans['C'] = 100; trans['D'] = 500; trans['M'] = 1000;
        for(int i = 0; i < s.size(); i++){
            if(i+1 < s.size() && trans[s[i]] < trans[s[i+1]]){
                sum -= trans[s[i]];
            }else{
                sum += trans[s[i]];
            }
        }
        return sum;
    }
};
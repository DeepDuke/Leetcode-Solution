class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        int minLen = strs[0].size();
        for(int i = 1; i < strs.size(); i++){
            if(strs[i].size() < minLen){
                minLen = strs[i].size();
            }
        }
        int cnt = 0;
        bool flag = true;
        for(int j = 0; j < minLen; j++){
            for(int k = 1; k < strs.size(); k++){ 
                if(strs[k][j] != strs[0][j]){
                    flag = false;
                    break;
                }
            }
            if(flag == false) break;
            cnt++;
        }
        if(cnt == 0) return "";
        else return strs[0].substr(0, cnt);
    }
};
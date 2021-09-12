// class Solution {
// private:
//     int count(int n){
//         int cnt = 0;
//         unsigned int flag = 1;
//         while(flag){
//             if(n & flag) cnt++;
//             flag <<= 1;
//         }
//         return cnt;
//     }
// public:
//     vector<int> countBits(int n) {
//         vector<int> ans;
//         for(int i = 0; i <=n; ++i){
//             ans.push_back(count(i));
//         }
//         return ans;
//     }
// };
class Solution {
private:
    int count(int n){
        int cnt = 0;
        while(n){
            cnt++;
            n &= (n-1);
        }
        return cnt;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <=n; ++i){
            ans.push_back(count(i));
        }
        return ans;
    }
};
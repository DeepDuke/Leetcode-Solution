/*
To avoid overflow, we can check ans and remainder
INT_MAX = 2147483647
INT_MIN = -2147483648
*/
class Solution {
public:
    int reverse(int x) {
        int ans = 0, pop = 0;
        while(x){
            if(ans > INT_MAX/10 || ans == INT_MAX/10 && pop > 7) return 0;
            if(ans < INT_MIN/10 || ans < INT_MIN/10 && pop < -8) return 0;
            pop = x % 10;
            ans = ans * 10 + pop;
            x /= 10;
        }
        return ans;
    }
};
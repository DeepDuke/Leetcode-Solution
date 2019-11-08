/*
Method: use two pointers, 从最外侧最宽的容器开始从两边向中间搜寻是否有容积更大的容器存在，
中间的容器由于宽度更窄，只有竖直短板更高的时候可能找到容积更大的容器。每次都从当前容器的更短的
竖直容器壁开始向中间搜寻。找到更高的容器壁时，计算新容器的体积。
Time: O(n)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;  // max area
        int L = 0, R = height.size()-1;
        while(L < R){
            int area = (R - L) * min(height[L], height[R]);
            ans = max(area, ans);
            if(height[L] < height[R]){
                L++;
                while(L < R && height[L] < height[L-1]) L++;
            }else{
                R--;
                while(L < R && height[R] < height[R+1]) R--;
            }
        }
        return ans;
    }
};
/*
 * Method One: use two pointers, set N = m + n, just count N/2 + 1 numbers from small to big ones.
 * Time: O(m+n)
 * */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p = 0, q = 0, N = nums1.size() + nums2.size();
        int cnt = 0;
        double res = 0.0;
        stack<int> st;
        // count N/2 numbers
        while(cnt < N / 2 +1 && p < nums1.size() && q < nums2.size()){
            if(nums1[p] > nums2[q]){
                st.push(nums2[q++]);
            }else{
                st.push(nums1[p++]);
            }
            cnt++;
        }
        while(cnt < N / 2 + 1 && p < nums1.size()) {
            st.push(nums1[p++]);
            cnt++;
        }
        while(cnt < N / 2 + 1 && q < nums2.size()) {
            st.push(nums2[q++]);
            cnt++;
        }
        // judge N is odd or even
        if(N & 1){
            res = st.top();
        }
        else{
            res += st.top(); st.pop();
            res += st.top();
            res /= 2;
        }
        return res;
    }
};

/*
 * Method Two: set N = m+n, convert this problem into finding k smallest number. To find a median number, if N is odd, 
 * just to find N/2+1 th smallest number; if N is even, just to find N/2 and N/2+1 th smallest numbers. Use a method similar 
 * to binary search to count k/2 numbers each time to achieve O(log(m+n)).
 * 
 * Time: O(log(m+n))
 * */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size() + nums2.size();
        if(N & 1) {
            return findKth(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, N/2 + 1);   
        }
        else{
            return (findKth(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, N/2 + 1)+findKth(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, N/2))/2.0;
        }
    }
    int findKth(vector<int>& nums1, int L1, int R1, vector<int>& nums2, int L2, int R2, int k){
        int len1 = R1 - L1 + 1, len2 = R2 - L2 + 1;
        // if(len1 > len2) return findKth(nums2, L2, R2, nums1, L1, R1, k);
        if(len1 == 0) return nums2[L2+k-1];
        if(len2 == 0) return nums1[L1+k-1];
        if(k == 1) return min(nums1[L1], nums2[L2]);
        
        int i = L1 + min(int(nums1.size()), k/2) - 1;
        int j = L2 + min(int(nums2.size()), k/2) - 1;
        if(nums1[i] < nums2[j]) return findKth(nums1, i+1, R1, nums2, L2, R2, k - (i-L1+1));
        else return findKth(nums1, L1, R1, nums2, j+1, R2, k - (j-L2+1));
    }
};
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> table(n+1);
        table[0] = 0, table[1] = 0;
        
        for(int i = 2; i <= n; ++i){
            table[i] = min(table[i-1]+cost[i-1], table[i-2]+cost[i-2]);
        }
        
        return table[n];
    }
};
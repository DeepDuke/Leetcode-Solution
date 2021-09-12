class Solution {
public:
    vector<int> table;
    
    int fib(int n){
        if(n == 0 || n == 1) return n;
        table.reserve(n+1);
        table[0] = 0, table[1] = 1;
        for(int i = 2; i <= n; i++){
            table[i] = table[i-1] + table[i-2];
        }
        return table[n];
    }
};
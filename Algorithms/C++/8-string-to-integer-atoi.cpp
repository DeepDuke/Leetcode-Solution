class Solution {
public:
    int myAtoi(string str) { 
        if(str.size() == 0) return 0;
        
        char sign = '+';
        int i = 0;
        while(str[i] == ' ') i++;
        if(str[i] != '+' && str[i] != '-' && (str[i] < '0' || str[i] > '9')) return 0;

        if(str[i] == '+' || str[i] == '-'){
            if(i == str.size()-1) return 0; // no element left
            if(str[i+1] < '0' || str[i+1] > '9') return 0; // no numerical digit
         
            sign = str[i];
            i++;
        }
        
        int num = str[i++] - '0';
        if(sign == '-') num = -num;
        for(; i < str.size(); i++){
            if(str[i] >= '0' && str[i] <= '9'){
                int digit = str[i] - '0';
                if(sign == '-') digit  = -digit;
                if(num > INT_MAX/10 || (num == INT_MAX/10 && digit > 7)){
                    return INT_MAX; 
                }
                if(num < INT_MIN/10 || num == INT_MIN/10 && digit < -8){
                    return INT_MIN; 
                }
                num = num * 10 + digit;
            }else{
                break;
            }            
        }
        return num;
    }
};
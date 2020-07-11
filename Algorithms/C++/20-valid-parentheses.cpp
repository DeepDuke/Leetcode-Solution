class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch: s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }else{
                if(st.empty()) return false;
                if(ch == ')'){  // case 1
                    if(st.top() == '(')  st.pop();
                    else return false;
                }else if(ch == ']'){  // case 2
                    if(st.top() == '[')  st.pop();
                    else return false;             
                }else{  // case 3
                    if(st.top() == '{') st.pop();
                    else return false;
                }
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto &c : s){   //here we dont need to write &
            if(c =='(' || c =='{' || c =='['){
                st.push(c);
            }
            else if(c ==')'){
                if(!st.empty() && st.top()=='(') st.pop();
                else return false;
            }
            else if(c =='}'){
                if(!st.empty() && st.top()=='{') st.pop();
                else return false;
            }
            else /*if(c ==']')*/{
                if(!st.empty() && st.top()=='[') st.pop();
                else return false;    
            }
        }
        return st.empty();
    }
    
};
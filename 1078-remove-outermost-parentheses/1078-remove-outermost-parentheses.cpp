class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int opened = 0;
        for (char c : s) {
            if (c == '(' && opened++ > 0) ans += c;
            if (c == ')' && opened-- > 1) ans += c;
        }
        return ans;
    }
};
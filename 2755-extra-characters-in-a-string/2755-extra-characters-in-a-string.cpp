class Solution {
public:
    int f_memo(int ind, int n, string str, unordered_set<string> &s, vector<int> &dp){
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];

        int a = 1 + f_memo(ind+1, n, str, s, dp);
        string s1 = "";
        for(int j = ind; j < n; j++) {
            s1 += str[j];
            if(s.count(s1)){
                a = min(a, f_memo(j+1, n, str, s, dp));
            }
        }
        return dp[ind] = a;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        vector<int> dp(n, -1);
        unordered_set<string> st;
        for(auto &it : dictionary) {
            st.insert(it);
        }
        return f_memo(0, n, s, st, dp);
    }
};
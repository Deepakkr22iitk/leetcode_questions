class Solution {
public:
    void compute(string &word, vector<vector<int>> &dp){
        int n = word.size();
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(word[i]==word[j]){
                    if(i+1<n && j+1<n) dp[i][j] = 1 + dp[i+1][j+1];
                    else dp[i][j] = 1;
                }
                else dp[i][j] = 0;
            }
        }
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        for(int i=0;i<n;i++){
            if(lcp[i][i] != n-i) return "";
        }

        string word(n,'?');
        char c = 'a';

        for(int i=0;i<n;i++){
            if(word[i]=='?'){
                if(c>'z') return "";
                word[i] = c;
                for(int j=i+1;j<n;j++){
                    if(lcp[i][j] > 0) word[j] = c;
                }
                c++;
            }
        }

        vector<vector<int>> dp(n, vector<int>(n,0));
        compute(word, dp);

        return dp==lcp ? word : "";
    }
};
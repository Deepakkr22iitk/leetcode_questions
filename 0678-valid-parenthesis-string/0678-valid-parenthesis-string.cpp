class Solution {
// Recursive Solution
    // bool f_recurr(int ind, int openingBracket, string &s){
    //     if(ind==s.size()) return (openingBracket==0);

    //     bool ans=false;
    //     if(s[ind]=='*'){
    //         ans|=f_recurr(ind+1,openingBracket+1,s); // Add '('
    //         if(openingBracket) ans|=f_recurr(ind+1,openingBracket-1,s); // Add ')'
    //         ans|=f_recurr(ind+1,openingBracket,s); //Add Nothing
    //     }else{
    //         if(s[ind]=='('){
    //             ans=f_recurr(ind+1,openingBracket+1,s);
    //         }else{
    //             if(openingBracket) ans=f_recurr(ind+1,openingBracket-1,s);
    //         }
    //     }
    //     return ans;
    // }

// Memoization  
    // bool f_memo(int ind, int openingBracket, string &s, vector<vector<int>> &dp){
    //     if(ind==s.size()) return (openingBracket==0);

    //     if(dp[ind][openingBracket]!=-1) return dp[ind][openingBracket];

    //     bool ans=false;
    //     if(s[ind]=='*'){
    //         ans|=f_memo(ind+1,openingBracket+1,s,dp);
    //         if(openingBracket) ans|=f_memo(ind+1,openingBracket-1,s,dp);
    //         ans|=f_memo(ind+1,openingBracket,s,dp);
    //     }else{
    //         if(s[ind]=='('){
    //             ans=f_memo(ind+1,openingBracket+1,s,dp);
    //         }else{
    //             if(openingBracket) ans=f_memo(ind+1,openingBracket-1,s,dp);
    //         }
    //     }

    //     return dp[ind][openingBracket]=ans;
    // }

public:
    bool checkValidString(string s) {
        // return f_recurr(0,0,s);

        // vector<vector<int>> dp(s.size(), vector<int>(s.size(),-1));
        // return f_memo(0,0,s,dp);

        //tabulation
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1,0));
        dp[s.size()][0]=1;

        for(int ind=s.size()-1; ind>=0; ind--){
            for(int openingBracket=0; openingBracket<s.size(); openingBracket++){
                bool ans=false;
                if(s[ind]=='*'){
                    ans|=dp[ind+1][openingBracket+1];
                    if(openingBracket) ans|=dp[ind+1][openingBracket-1];
                    ans|=dp[ind+1][openingBracket];
                }else{
                    if(s[ind]=='('){
                        ans|=dp[ind+1][openingBracket+1];
                    }else{
                        if(openingBracket) ans|=dp[ind+1][openingBracket-1];
                    }
                }

                dp[ind][openingBracket]=ans;
            }
        }

        return dp[0][0];
    }
};
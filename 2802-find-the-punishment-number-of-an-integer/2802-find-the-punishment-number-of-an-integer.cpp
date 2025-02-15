class Solution {
public:
    // In this problem, Brute force is more optimized compared to the DP based implementation :)
    // The time complexity of this approach is O(n*2^l)== O(N*2^(log10(N^2)))== O(N^1.602) [l==length of the square number i.e., l==log10(i*i)]
    bool check(string str,int i,int ind,int val)
    {
        if(ind==str.size())
        {
            if(val==i) return true;
            return false;
        }

        for(int k=1;(k+ind)<=str.size();++k)
        {
            string temp=str.substr(ind,k);
            int num=stoi(temp);
            int n_val=val+num;
            
            bool flag=false;
            if(n_val<=i) flag=check(str,i,(ind+k),n_val);
            if(flag==true) return true;
        }
        return false;
    }


    // The Time Complexity of this approach is O(n*(len*1000))  [len==length of string, and 1000 equals the maxm sum we need to make]
    // Notice that we have n≤1000, that means n^2≤1000000, so we are basically dealing with 6 digits numbers. This makes brutal force (O(3∗2^6) ops) 
    // much faster than any attempt to uses DP (O(1000∗6^2) ops).

    // bool check2(string &str, int &orig, int ind, int sum, vector<vector<int>>&dp)
    // {
    //     if(ind==str.size()) return (sum==orig);

    //     if(dp[ind][sum]!=-1) return dp[ind][sum];

    //     for(int len=1;(len+ind)<=str.size();++len)
    //     {
    //         string curr=str.substr(ind,len);
    //         int curr_val=stoi(curr);
    //         if((sum+curr_val)<=orig) 
    //         {
    //             if(check2(str,orig,(ind+len), (sum+curr_val),dp)) return true;
    //         }
    //     }
    //     return dp[ind][sum]=0;
    // }
    int punishmentNumber(int n) {
        // Some Hardcoded values
        if(n<9) return 1;

        if(n==9) return 82;

        if(n>=10 && n<36) return 182;

        int ans=1478;         // ans for n==36
        for(int i=37;i<=n;++i)
        {
            int val=i*i;
            string str=to_string(val);
            if(check(str,i,0,0)) ans+=val;

            // int len=str.size();
            // vector<vector<int>>dp(len,vector<int>(i+1,-1));
            // if(check2(str,i,0,0,dp)) ans+=val;
        }
        return ans;
    }
};
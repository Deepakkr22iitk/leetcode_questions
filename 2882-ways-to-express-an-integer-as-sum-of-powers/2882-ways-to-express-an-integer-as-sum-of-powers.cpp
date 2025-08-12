// class Solution {
// public:
//     int mod=1e9+7;
//     int solve(int n,int x,int now,auto &dp)
//     {
//         if(n==0) return 1;
//         else if(pow(now,x)>n) return 0;

//         if(dp[n][now]!=-1) return dp[n][now];
//         return dp[n][now]=(solve(n-pow(now,x),x,now+1,dp)%mod+solve(n,x,now+1,dp)%mod)%mod;
//     }
//     int numberOfWays(int n, int x) {
//         vector<vector<int>> dp(n,vector<int>(301,-1));
//         return solve(n,x,1,dp);
//     }
// };

class Solution {
public:
     int mod = 1e9+7;
     int dp[301][301];
    
     int f(int n, int num, int x ) {
            if(n < 0 )return 0; 
            if(n == 0)return 1; 
            if(pow(num , x) > n) return 0;
            if(dp[n][num] != -1) return dp[n][num];
          
            int temp = pow(num , x) ;
            
            int pick = f(n- temp , num + 1 , x);
            int skip = f(n , num + 1 , x);
            
            return dp[n][num] =  (skip % mod + pick % mod) % mod ;
    }
    
    
    int numberOfWays(int n, int x) {
        memset(dp, -1, sizeof(dp));
        return f(n, 1, x);
    }
};
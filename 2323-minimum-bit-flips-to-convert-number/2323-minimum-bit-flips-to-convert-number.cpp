class Solution {
public:
    int countSetBits(int x)
    {
        int cnt=0;
        while(x>1)
        {
            cnt+=(x&1);
            x=x>>1;
        }
        if(x==1) cnt++;
        return cnt;
    }
    int minBitFlips(int start, int goal) {
        int ans=0;
        // solution 1
        // while(start>0 || goal>0)
        // {
        //     if((start&1) != (goal&1)) ans++;
        //     start=start>>1;
        //     goal=goal>>1;
        // }

        // solution 2
        // while(start>0 && goal>0)
        // {
        //     if((start&1) != (goal&1)) ans++;
        //     start=start>>1;
        //     goal=goal>>1;
        // }
        // while(start)
        // {
        //     ans+=(start&1);
        //     start=start>>1;
        // }
        // while(goal)
        // {
        //     ans+=(goal&1);
        //     goal=goal>>1;
        // }

        // solution 3
        ans=countSetBits(start^goal);
        return ans;
    }
};
class Solution {
public:
    // Assume we start with a = 0,
    // continuously calculate the next value by difference.
    // We only need to record the current value a, the max and the min value in this sequence.

    // Now we need to put the sequence with range [min, max] into a range of [lower, upper].

    // If upper - lower < max - min, no possible hidden sequences.
    // If upper - lower == max - min, we have only 1 possible hidden sequences.
    // If upper - lower == max - min + 1, we have 2 possible hidden sequences.
    // If upper - lower == max - min + k, we have k + 1 possible hidden sequences.

    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n=differences.size();
        // int mx=upper-lower;
        // for(auto &x:differences)
        // {
        //     if(abs(x)>mx) return 0;
        // }
    
        // for(int prev=lower;prev<=upper;++prev)
        // {
        //     int val=prev;
        //     int i=0;
        //     int mxm=prev;
        //     for(;i<n;++i)
        //     {
        //         int nxt=val+differences[i];
        //         if(nxt>upper || nxt<lower) break;

        //         val=nxt;
        //         mxm=max(mxm,nxt);
        //     }
        //     if(i==n)
        //     {
        //         int ans=(upper-mxm+1);
        //         return ans;
        //     }
        // }
        // return 0;

        int prev=0,mx=0,mn=0;
        for(auto &x:differences)
        {
            prev+=x;
            mx=max(mx,prev);
            mn=min(mn,prev);
            if((mx-mn)>(upper-lower)) return 0;
        }

        int ans=(upper-lower)-(mx-mn)+1;
        return ans;
    }
};
class Solution {
public:
    // ✅ Optimized Approach (O(n²))
    // We fix a binary pair (j, k) such that j < k and |arr[j] - arr[k]| <= b.
    // Now, we just need to count how many i < j satisfy:

    // |arr[i] - arr[j]| <= a
    // |arr[i] - arr[k]| <= c
    // These two conditions translate to:

    // arr[i] ∈ [arr[j] - a, arr[j] + a]
    // arr[i] ∈ [arr[k] - c, arr[k] + c]
    // So the values of arr[i] that satisfy both lie in the intersection of these two intervals:
    // Let sum[x]=no. of values<=x that occured before index 'j'

    // Now we need to count how many i < j such that arr[i] ∈ [l, r].
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n=arr.size();
        int ans=0;

        vector<int>sum(1001);

        for(int j=0;j<n;++j)
        {
            for(int k=j+1;k<n;++k)
            {
                if(abs(arr[j]-arr[k])<=b)
                {
                    // Define intersection range [l, r] for valid arr[i]
                    int lj=arr[j]-a;
                    int rj=arr[j]+a;
                    int lk=arr[k]-c;
                    int rk=arr[k]+c;

                    int l=max(0,max(lj,lk));
                    int r=min(1000,min(rj,rk));

                    if(l<=r)
                    {
                        if(l==0) ans+=sum[r];

                        else ans+=(sum[r]-sum[l-1]);
                    }
                }
            }
            
            // Update prefix sum: add arr[j] for future queries (j < future k)
            for(int k=arr[j];k<=1000;++k) sum[k]++;
        }
        return ans;
    }
};
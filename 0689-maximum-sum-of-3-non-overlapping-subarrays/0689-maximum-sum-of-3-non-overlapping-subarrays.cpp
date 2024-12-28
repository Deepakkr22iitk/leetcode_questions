class Solution {
public:
    // The idea is that check for potential answer at each of the index.
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>left(n),right(n); // 'left' vector keeps track of the index no. on it's left side such that starting from that particular
        vector<int>pre(n); //index and take a subarray of 'k' we got the maximum possible sum.In sample-1 left[7]=4 and similarly keeping track of the right side too. 
        pre[0]=nums[0];    // It may also be possible that for any particular index the end index of the subarray ends at 'i'. e.g., left[5]=4
        for(int i=1;i<n;++i)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        int i=0;
        int j=0;
        long long sum=0;
        for(;j<k;++j)
        {
            sum+=1LL*nums[j];
        }
        
        long long mx=sum;   //current maximum sum of subarray of length k from left side.
        while(j<n)     // Now start building left vector after index 'k'
        {
            left[j]=left[j-1];
            sum-=1LL*nums[i];
            i++;
            sum+=1LL*nums[j];
            if(sum>mx) left[j]=i;
            mx=max(mx,sum);
            j++;
        }

        j=n-1;
        i=n-1;
        sum=0;   // Keep track of the sum of first subarray from right
        while(j>=(n-k))
        {
            sum+=1LL*nums[j];
            j--;
        }
        right[j+1]=j+1;   // For first subarray of length 'k' this index value for right should be 'j+1'
        mx=sum;
        while(j>=0)
        {
            right[j]=right[j+1];
            sum-=1LL*nums[i];
            i--;
            sum+=1LL*nums[j];
            if(sum>=mx) right[j]=j;
            mx=max(mx,sum);
            j--;
        }

        vector<int>ans(3);   // Now checking each of the possiblity 
        int total=0;
        for(int j=k;j<=(n-2*k);++j)
        {
            int l=left[j-1];   // Index of the maximum sum possible before this particular index 
            int r=right[j+k];  // Index of the maximum sum far by index 'k' from the particular index on right side.

            int sum1=pre[l+k-1];
            if(l>0) sum1-=pre[l-1];

            int sum2=pre[j+k-1]-pre[j-1];    // Considering one of the subarray starting from my current index 'j'

            int sum3=pre[r+k-1]-pre[r-1];

            if((sum1+sum2+sum3)>total)
            {
                ans[0]=l;
                ans[1]=j;
                ans[2]=r;
                total=sum1+sum2+sum3;
            }
        }
        return ans;
    }
};
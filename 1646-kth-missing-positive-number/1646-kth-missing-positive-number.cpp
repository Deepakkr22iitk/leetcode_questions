class Solution {
public:
    // it's simple to do this in O(n) but can we do this in O(log(n))?
    // trying to do that
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        if(arr[0]>k) return k;
        // solution 1 TC->O(n)
        // int last=0,idx=0,miss=0;
        // while(idx<n && (miss+(arr[idx]-last-1))<k)
        // {
        //     miss+=(arr[idx]-last-1);
        //     last=arr[idx];
        //     idx++;
        // }
        // return arr[--idx]+k-miss;

        // solution 2 TC->O(log(n))
        if(k<=arr[0]-1) return k;
        if(k>(arr[n-1]-n)) return arr[n-1]+(k-(arr[n-1]-n));
        int low=0,high=n-1,ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if((arr[mid]-(mid+1))>=k)
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return arr[ans]-((arr[ans]-(ans+1))-k)-1;
    }
};
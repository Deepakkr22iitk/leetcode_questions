class Solution {
public:
    // it's simple to do this in O(n) but can we do this in O(log(n))?
    // trying to do that
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int last=0,idx=0,miss=0;
        if(arr[0]>k) return k;
        while(idx<n && (miss+(arr[idx]-last-1))<k)
        {
            miss+=(arr[idx]-last-1);
            last=arr[idx];
            idx++;
        }
        return arr[--idx]+k-miss;
    }
};
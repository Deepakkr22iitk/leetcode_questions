class Solution {
public:
    // The idea is to count the number of good pairs instead of bad pairs and then subtract it.
    // j-i!=nums[j]-nums[i] ==> nums[i]-i !=nums[j]-j
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        map<int,int>freq;
        for(long long i=0;i<n;i++)
        {
            freq[(nums[i]-i)]++;
        }
        long long cnt=0;
        for(auto m:freq)
        {
            long long l=(long long)m.second;
            cnt+=((l-1)*l)/2;
        }
        return (long long)(n*(n-1))/2 -cnt;
    }
};
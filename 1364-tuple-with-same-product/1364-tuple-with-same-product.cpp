class Solution {
public:
    // The idea is that any of quadruples can be arranged in 8 ways and for any particular product--> no. of pairs that can be formed
    // is nC2 ==> n*(n-1)/2
    // And all of these calculations are possible with the given constraints.
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        map<int,int>freq;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                int prod=nums[i]*nums[j];
                freq[prod]++;
            }
        }

        for(auto &x:freq)
        {
            int curr=x.second;
            int pairs=(curr*(curr-1))/2;

            ans+=pairs*8;
        }
        return ans;
    }
};
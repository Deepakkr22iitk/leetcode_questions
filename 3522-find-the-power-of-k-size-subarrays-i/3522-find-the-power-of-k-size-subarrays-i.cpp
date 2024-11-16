class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1) return nums;
        int n=nums.size();
        vector<int>ans(n-k+1,-1);
        int cont=1;
        for(int i=1;i<n;++i)
        {
            if((nums[i-1]+1)==nums[i]) cont++;
            else cont=1;

            if(cont>=k) ans[i-k+1]=nums[i];  // Here we are using >=k and not (==k) --> [1,2,3,4,5,6,7,8,9] for this scene,
        }                                    // Here >=k are consecutive and sorted in ascending order
        return ans;
    }
};
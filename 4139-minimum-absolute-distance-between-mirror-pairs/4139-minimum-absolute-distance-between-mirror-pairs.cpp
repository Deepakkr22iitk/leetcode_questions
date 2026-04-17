class Solution {
public:

    int reverseNum(int x){
        int rev = 0;
        while(x){
            rev = rev*10 + x%10;
            x/=10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = INT_MAX;

        for(int j=0;j<nums.size();j++){
            if(mp.count(nums[j])){
                ans = min(ans, j - mp[nums[j]]);
            }

            int rev = reverseNum(nums[j]);
            mp[rev] = j;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
      int maxi=INT_MIN,mini=INT_MAX;
      for(int x:nums){
        maxi=max(maxi,x);mini=min(mini,x);
      }
      return 1LL*k*(maxi-mini);
    }
};
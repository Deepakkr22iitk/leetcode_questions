class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        
        int maxi=0;
        unordered_set<int>even,odd;
        for(int i=0;i<nums.size();i++){
            even.clear();
            odd.clear();
            for(int j=i;j<nums.size();j++){
                if((nums[j]&1)==0)even.insert(nums[j]);
                else odd.insert(nums[j]);
            if(even.size()==odd.size())maxi=max(maxi,j-i+1);
            }
            
        }
        return maxi;
    }
};
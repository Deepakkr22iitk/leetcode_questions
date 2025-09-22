class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
       unordered_map<int,int>umap;
       int maxi=INT_MIN;
       for(int i=0;i<nums.size();i++){
           umap[nums[i]]++;
           if(umap[nums[i]]>maxi){
               maxi=umap[nums[i]];
           }
       }
       int ans=0;
       for(auto it:umap){
         if(it.second==maxi){
       ans=ans+maxi;
            }
       }
       return ans;
    }
};
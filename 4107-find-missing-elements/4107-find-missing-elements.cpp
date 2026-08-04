class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int start=*min_element(nums.begin(),nums.end());
        int end=*max_element(nums.begin(),nums.end());

        vector<bool> present(end-start+1,false);
        for(int i=0;i<nums.size();++i)
        {
            present[nums[i]-start]=true;
        }

        vector<int> ans;
        for(int i=0;i<present.size();++i)
        {
            if(present[i]==false) ans.push_back(i+start);
        }

        return ans;
    }
};
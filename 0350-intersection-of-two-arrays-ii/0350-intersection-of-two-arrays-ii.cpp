class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        map<int,int> freq;
        for(int i=0;i<nums1.size();i++){
            freq[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(freq[nums2[i]]>0){
                freq[nums2[i]]--;
                v.push_back(nums2[i]);
            }
        }
        return v;
    }
};
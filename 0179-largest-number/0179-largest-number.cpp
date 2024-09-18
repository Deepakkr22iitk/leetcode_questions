class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string>dk;
        for(int i=0;i<n;++i)
        {
            dk.push_back(to_string(nums[i]));
        }

        sort(dk.begin(),dk.end(), [](string &a,string &b){
            return (a+b)>(b+a);
        });

        if(dk[0]=="0") return "0";
        string ans="";
        for(int i=0;i<n;++i)
        {
            ans+=dk[i];
        }
        return ans;
    }
};
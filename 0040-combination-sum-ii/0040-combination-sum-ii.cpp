class Solution {
public:
    void helper(vector<int>&candidates,vector<int>&temp,int ind,int sum,set<vector<int>>&ans,int target,int n)
    {
        if(sum>target || ind>=n)
        {
            if(sum==target) ans.insert(temp);
            return;
        }
        if(sum==target)
        {
            ans.insert(temp);
            return;
        } 
        for(int i=ind;i<n;++i)
        {
            if(i!=ind && candidates[i]==candidates[i-1]) continue;

            temp.push_back(candidates[i]);
            helper(candidates,temp,i+1,sum+candidates[i],ans,target,n);
            temp.pop_back();
        }
        // temp.push_back(candidates[ind]);
        // helper(candidates,temp,ind+1,sum+candidates[ind],ans,target,n);
        // temp.pop_back();
        // helper(candidates,temp,ind+1,sum,ans,target,n);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<vector<int>>res;
        set<vector<int>>st;
        vector<int>temp;
        helper(candidates,temp,0,0,st,target,n);
        for(auto &x:st) res.push_back(x);
        return res;
    }
};
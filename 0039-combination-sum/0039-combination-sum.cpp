class Solution {
public:
    vector<vector<int>>ans;
    void prints(int idx, vector<int> &arr, vector<int>& temp, int target) {
        if(target==0){
            ans.push_back(temp);
            return; 
        }
        if(target<0)
            return;

        if(idx==arr.size())
            return;
        
        prints(idx + 1, arr, temp, target);
        temp.push_back(arr[idx]);

        prints(idx , arr,temp, target-arr[idx]);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        ans.clear(); 
        
        vector<int> temp; 
        prints(0, arr, temp, target); 
        
        return ans; // finally return the answer array
    }
};
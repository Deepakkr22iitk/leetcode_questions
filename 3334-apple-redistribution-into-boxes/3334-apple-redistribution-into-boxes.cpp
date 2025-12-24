class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        int total=accumulate(apple.begin(),apple.end(),0);
        int n=capacity.size();
        int ans=0,idx=n-1;;
        while(total>0)
        {
            total-=capacity[idx];
            ans++;
            idx--;
        }
        return ans;
    }
};
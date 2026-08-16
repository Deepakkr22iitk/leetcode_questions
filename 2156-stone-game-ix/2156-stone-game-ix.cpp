class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();

        vector<int> rem(3,0);
        for(auto x:stones)
        {
            rem[x%3]++;
        }
        if(rem[0]%2==0) return rem[1]>0 && rem[2]>0;
        return abs(rem[1]-rem[2])>2;
    }
};
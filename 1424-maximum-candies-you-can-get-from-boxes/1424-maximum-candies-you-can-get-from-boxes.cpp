class Solution {
public:
    // Simply do whatever is told as per the problem
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int res=0;
        bool flag=true;
        while(!initialBoxes.empty() && flag)
        {
            flag=false;
            vector<int>curr;
            for(int box: initialBoxes)
            {
                if(status[box]==1)
                {
                    flag=true;
                    vector<int>temp=containedBoxes[box];
                    int len=temp.size();
                    for(int j=0;j<len;++j)
                    {
                        curr.push_back(temp[j]);
                    }
                    for(auto &key: keys[box]) status[key]=1;
                    res+=candies[box];
                }
                else curr.push_back(box);
            }

            initialBoxes=curr;
        }
        return res;
    }
};
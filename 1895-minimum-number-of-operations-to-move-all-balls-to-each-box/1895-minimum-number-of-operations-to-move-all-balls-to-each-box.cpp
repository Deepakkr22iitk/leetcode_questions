class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        int n=boxes.size();
        int sum=0;
        int fromLast=0;
        for(int i=1;i<n;++i)
        {
            if(boxes[i]=='1') 
            {
                sum+=i;
                fromLast++;
            }
        }
        int tillNow=0;
        for(int i=0;i<n;++i)
        {
            if(boxes[i]=='1') 
            {
                tillNow++;
                if(i>0) fromLast--;
            }
            ans.push_back(sum);
            sum-=fromLast;
            sum+=tillNow;
        }
        return ans;
    }
};
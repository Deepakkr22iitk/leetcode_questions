class Solution {
public:
     int perform(int i,int j,char ch)
     {
         if(ch=='+') return (i+j);
         if(ch=='-') return (i-j);
         if(ch=='*') return (i*j);
         return 0;
     }
    vector<int> diffWaysToCompute(string expression) {
        vector<int>ans;
        bool isnum=true;
        for(int i=0;i<expression.size();++i)
        {
            if(!isdigit(expression[i]))
            {
                vector<int>left=diffWaysToCompute(expression.substr(0,i));
                vector<int>right=diffWaysToCompute(expression.substr(i+1));
                isnum=false;
                for(int x:left)
                {
                    for(int y:right)
                    {
                        int val=perform(x,y,expression[i]);
                        ans.push_back(val);
                    }
                }
            }
        }
        if(isnum) ans.push_back(stoi(expression));
        return ans;
    }
};
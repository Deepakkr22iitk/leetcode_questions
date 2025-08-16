class Solution {
public:
    int maximum69Number (int num) {
        int ans=0,flag=1;
        string given=to_string(num);
        for(int i=0;i<given.size();++i)
        {
            ans*=10;
            if(flag && given[i]=='6')
            {
                ans+=9;
                flag=0;
            }
            else ans+=(given[i]-'0');
        }
        return ans;
    }
};
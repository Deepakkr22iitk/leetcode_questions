class Solution {
public:
    set<string>st;
    int ans=1;
    void helper(int ind,int n,string s,string temp,int cnt)
    {
        if(ind==n)
        {
            if(temp.size()>0 && st.find(temp)==st.end())
            {
                cnt++;
            }
            ans=max(ans,cnt);
            return;
        }

        string curr="";
        curr+=s[ind];

        helper(ind+1,n,s,temp+curr,cnt);

        temp=temp+curr;
        if(temp.size()>0 && st.find(temp)==st.end())
        {
            st.insert(temp);
            helper(ind+1,n,s,"",cnt+1);
            st.erase(temp);
        }
    }
    int maxUniqueSplit(string s) {
        int n=s.size();
        string temp="";
        int cnt=0;
        helper(0,n,s,temp,cnt);
        return ans;
    }
};